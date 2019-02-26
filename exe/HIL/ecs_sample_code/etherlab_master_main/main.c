/*****************************************************************************
 *
 *  $Id$
 *
 *  Copyright (C) 2007-2009  Florian Pose, Ingenieurgemeinschaft IgH
 *
 *  This file is part of the IgH EtherCAT Master.
 *
 *  The IgH EtherCAT Master is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License version 2, as
 *  published by the Free Software Foundation.
 *
 *  The IgH EtherCAT Master is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 *  Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with the IgH EtherCAT Master; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  ---
 *
 *  The license mentioned above concerns the source code only. Using the
 *  EtherCAT technology and brand is only permitted in compliance with the
 *  industrial property and similar rights of Beckhoff Automation GmbH.
 *
 ****************************************************************************/

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h> /* clock_gettime() */
#include <sys/mman.h> /* mlockall() */
#include <sched.h> /* sched_setscheduler() */

/****************************************************************************/

#include "ecrt.h"

/****************************************************************************/

/** Task period in ns. */
#define PERIOD_NS   (1000000)

#define MAX_SAFE_STACK (8 * 1024) /* The maximum stack size which is
                                     guranteed safe to access without
                                     faulting */
/****************************************************************************/

/* Constants */
#define NSEC_PER_SEC (1000000000)
#define FREQUENCY (NSEC_PER_SEC / PERIOD_NS)
/****************************************************************************/

/*domain reg*/

// EtherCAT
static ec_master_t *master = NULL;
static ec_master_state_t master_state = {};

static ec_domain_t *domain1 = NULL;
static ec_domain_state_t domain1_state = {};

static ec_domain_t *domain2 = NULL;
static ec_domain_state_t domain2_state = {};

static ec_slave_config_t *cifxecs =NULL;
static ec_slave_config_state_t cifxecs_state = {};
/****************************************************************************/
#define PDO_OU_REG(y) {CIFXECS_POS , CIFXECS_CARD, 0x2000, y, output + y},
#define PDO_IN_REG(y) {CIFXECS_POS , CIFXECS_CARD, 0x3000, y, input  + y},

// process data
static uint8_t *domain1_pd = NULL;
static uint8_t *domain2_pd = NULL;

/*
 *
 *
 */
#define CIFXECS_POS 0, 0
#define CIFXECS_CARD 0xE0000044, 0x00000001 

ec_pdo_entry_info_t slave_0_pdo_entries[] = {
    {0x2000, 0x01, 8}, /* 1 Byte Out (0) */
    {0x2000, 0x02, 8}, /* 1 Byte Out (1) */
    {0x2000, 0x03, 8}, /* 1 Byte Out (2) */
    {0x2000, 0x04, 8}, /* 1 Byte Out (3) */
    {0x2000, 0x05, 8}, /* 1 Byte Out (4) */
    {0x2000, 0x06, 8}, /* 1 Byte Out (5) */
    {0x2000, 0x07, 8}, /* 1 Byte Out (6) */
    {0x2000, 0x08, 8}, /* 1 Byte Out (7) */
    {0x2000, 0x09, 8}, /* 1 Byte Out (8) */
    {0x2000, 0x0a, 8}, /* 1 Byte Out (9) */
    {0x2000, 0x0b, 8}, /* 1 Byte Out (10) */
    {0x2000, 0x0c, 8}, /* 1 Byte Out (11) */
    {0x2000, 0x0d, 8}, /* 1 Byte Out (12) */
    {0x2000, 0x0e, 8}, /* 1 Byte Out (13) */
    {0x2000, 0x0f, 8}, /* 1 Byte Out (14) */
    {0x2000, 0x10, 8}, /* 1 Byte Out (15) */
    {0x2000, 0x11, 8}, /* 1 Byte Out (16) */
    {0x2000, 0x12, 8}, /* 1 Byte Out (17) */
    {0x2000, 0x13, 8}, /* 1 Byte Out (18) */
    {0x2000, 0x14, 8}, /* 1 Byte Out (19) */
    {0x2000, 0x15, 8}, /* 1 Byte Out (20) */
    {0x2000, 0x16, 8}, /* 1 Byte Out (21) */
    {0x2000, 0x17, 8}, /* 1 Byte Out (22) */
    {0x2000, 0x18, 8}, /* 1 Byte Out (23) */
    {0x2000, 0x19, 8}, /* 1 Byte Out (24) */
    {0x2000, 0x1a, 8}, /* 1 Byte Out (25) */
    {0x2000, 0x1b, 8}, /* 1 Byte Out (26) */
    {0x2000, 0x1c, 8}, /* 1 Byte Out (27) */
    {0x2000, 0x1d, 8}, /* 1 Byte Out (28) */
    {0x2000, 0x1e, 8}, /* 1 Byte Out (29) */
    {0x2000, 0x1f, 8}, /* 1 Byte Out (30) */
    {0x2000, 0x20, 8}, /* 1 Byte Out (31) */
    {0x2000, 0x21, 8}, /* 1 Byte Out (32) */
    {0x2000, 0x22, 8}, /* 1 Byte Out (33) */
    {0x2000, 0x23, 8}, /* 1 Byte Out (34) */
    {0x2000, 0x24, 8}, /* 1 Byte Out (35) */
    {0x2000, 0x25, 8}, /* 1 Byte Out (36) */
    {0x2000, 0x26, 8}, /* 1 Byte Out (37) */
    {0x2000, 0x27, 8}, /* 1 Byte Out (38) */
    {0x2000, 0x28, 8}, /* 1 Byte Out (39) */
    {0x2000, 0x29, 8}, /* 1 Byte Out (40) */
    {0x2000, 0x2a, 8}, /* 1 Byte Out (41) */
    {0x2000, 0x2b, 8}, /* 1 Byte Out (42) */
    {0x2000, 0x2c, 8}, /* 1 Byte Out (43) */
    {0x2000, 0x2d, 8}, /* 1 Byte Out (44) */
    {0x2000, 0x2e, 8}, /* 1 Byte Out (45) */
    {0x2000, 0x2f, 8}, /* 1 Byte Out (46) */
    {0x2000, 0x30, 8}, /* 1 Byte Out (47) */
    {0x2000, 0x31, 8}, /* 1 Byte Out (48) */
    {0x2000, 0x32, 8}, /* 1 Byte Out (49) */
    {0x2000, 0x33, 8}, /* 1 Byte Out (50) */
    {0x2000, 0x34, 8}, /* 1 Byte Out (51) */
    {0x2000, 0x35, 8}, /* 1 Byte Out (52) */
    {0x2000, 0x36, 8}, /* 1 Byte Out (53) */
    {0x2000, 0x37, 8}, /* 1 Byte Out (54) */
    {0x2000, 0x38, 8}, /* 1 Byte Out (55) */
    {0x2000, 0x39, 8}, /* 1 Byte Out (56) */
    {0x2000, 0x3a, 8}, /* 1 Byte Out (57) */
    {0x2000, 0x3b, 8}, /* 1 Byte Out (58) */
    {0x2000, 0x3c, 8}, /* 1 Byte Out (59) */
    {0x2000, 0x3d, 8}, /* 1 Byte Out (60) */
    {0x2000, 0x3e, 8}, /* 1 Byte Out (61) */
    {0x2000, 0x3f, 8}, /* 1 Byte Out (62) */
    {0x2000, 0x40, 8}, /* 1 Byte Out (63) */
    {0x2000, 0x41, 8}, /* 1 Byte Out (64) */
    {0x2000, 0x42, 8}, /* 1 Byte Out (65) */
    {0x2000, 0x43, 8}, /* 1 Byte Out (66) */
    {0x2000, 0x44, 8}, /* 1 Byte Out (67) */
    {0x2000, 0x45, 8}, /* 1 Byte Out (68) */
    {0x2000, 0x46, 8}, /* 1 Byte Out (69) */
    {0x2000, 0x47, 8}, /* 1 Byte Out (70) */
    {0x2000, 0x48, 8}, /* 1 Byte Out (71) */
    {0x2000, 0x49, 8}, /* 1 Byte Out (72) */
    {0x2000, 0x4a, 8}, /* 1 Byte Out (73) */
    {0x2000, 0x4b, 8}, /* 1 Byte Out (74) */
    {0x2000, 0x4c, 8}, /* 1 Byte Out (75) */
    {0x2000, 0x4d, 8}, /* 1 Byte Out (76) */
    {0x2000, 0x4e, 8}, /* 1 Byte Out (77) */
    {0x2000, 0x4f, 8}, /* 1 Byte Out (78) */
    {0x2000, 0x50, 8}, /* 1 Byte Out (79) */
    {0x2000, 0x51, 8}, /* 1 Byte Out (80) */
    {0x2000, 0x52, 8}, /* 1 Byte Out (81) */
    {0x2000, 0x53, 8}, /* 1 Byte Out (82) */
    {0x2000, 0x54, 8}, /* 1 Byte Out (83) */
    {0x2000, 0x55, 8}, /* 1 Byte Out (84) */
    {0x2000, 0x56, 8}, /* 1 Byte Out (85) */
    {0x2000, 0x57, 8}, /* 1 Byte Out (86) */
    {0x2000, 0x58, 8}, /* 1 Byte Out (87) */
    {0x2000, 0x59, 8}, /* 1 Byte Out (88) */
    {0x2000, 0x5a, 8}, /* 1 Byte Out (89) */
    {0x2000, 0x5b, 8}, /* 1 Byte Out (90) */
    {0x2000, 0x5c, 8}, /* 1 Byte Out (91) */
    {0x2000, 0x5d, 8}, /* 1 Byte Out (92) */
    {0x2000, 0x5e, 8}, /* 1 Byte Out (93) */
    {0x2000, 0x5f, 8}, /* 1 Byte Out (94) */
    {0x2000, 0x60, 8}, /* 1 Byte Out (95) */
    {0x2000, 0x61, 8}, /* 1 Byte Out (96) */
    {0x2000, 0x62, 8}, /* 1 Byte Out (97) */
    {0x2000, 0x63, 8}, /* 1 Byte Out (98) */
    {0x2000, 0x64, 8}, /* 1 Byte Out (99) */
    {0x2000, 0x65, 8}, /* 1 Byte Out (100) */
    {0x2000, 0x66, 8}, /* 1 Byte Out (101) */
    {0x2000, 0x67, 8}, /* 1 Byte Out (102) */
    {0x2000, 0x68, 8}, /* 1 Byte Out (103) */
    {0x2000, 0x69, 8}, /* 1 Byte Out (104) */
    {0x2000, 0x6a, 8}, /* 1 Byte Out (105) */
    {0x2000, 0x6b, 8}, /* 1 Byte Out (106) */
    {0x2000, 0x6c, 8}, /* 1 Byte Out (107) */
    {0x2000, 0x6d, 8}, /* 1 Byte Out (108) */
    {0x2000, 0x6e, 8}, /* 1 Byte Out (109) */
    {0x2000, 0x6f, 8}, /* 1 Byte Out (110) */
    {0x2000, 0x70, 8}, /* 1 Byte Out (111) */
    {0x2000, 0x71, 8}, /* 1 Byte Out (112) */
    {0x2000, 0x72, 8}, /* 1 Byte Out (113) */
    {0x2000, 0x73, 8}, /* 1 Byte Out (114) */
    {0x2000, 0x74, 8}, /* 1 Byte Out (115) */
    {0x2000, 0x75, 8}, /* 1 Byte Out (116) */
    {0x2000, 0x76, 8}, /* 1 Byte Out (117) */
    {0x2000, 0x77, 8}, /* 1 Byte Out (118) */
    {0x2000, 0x78, 8}, /* 1 Byte Out (119) */
    {0x2000, 0x79, 8}, /* 1 Byte Out (120) */
    {0x2000, 0x7a, 8}, /* 1 Byte Out (121) */
    {0x2000, 0x7b, 8}, /* 1 Byte Out (122) */
    {0x2000, 0x7c, 8}, /* 1 Byte Out (123) */
    {0x2000, 0x7d, 8}, /* 1 Byte Out (124) */
    {0x2000, 0x7e, 8}, /* 1 Byte Out (125) */
    {0x2000, 0x7f, 8}, /* 1 Byte Out (126) */
    {0x2000, 0x80, 8}, /* 1 Byte Out (127) */
    {0x2000, 0x81, 8}, /* 1 Byte Out (128) */
    {0x2000, 0x82, 8}, /* 1 Byte Out (129) */
    {0x2000, 0x83, 8}, /* 1 Byte Out (130) */
    {0x2000, 0x84, 8}, /* 1 Byte Out (131) */
    {0x2000, 0x85, 8}, /* 1 Byte Out (132) */
    {0x2000, 0x86, 8}, /* 1 Byte Out (133) */
    {0x2000, 0x87, 8}, /* 1 Byte Out (134) */
    {0x2000, 0x88, 8}, /* 1 Byte Out (135) */
    {0x2000, 0x89, 8}, /* 1 Byte Out (136) */
    {0x2000, 0x8a, 8}, /* 1 Byte Out (137) */
    {0x2000, 0x8b, 8}, /* 1 Byte Out (138) */
    {0x2000, 0x8c, 8}, /* 1 Byte Out (139) */
    {0x2000, 0x8d, 8}, /* 1 Byte Out (140) */
    {0x2000, 0x8e, 8}, /* 1 Byte Out (141) */
    {0x2000, 0x8f, 8}, /* 1 Byte Out (142) */
    {0x2000, 0x90, 8}, /* 1 Byte Out (143) */
    {0x2000, 0x91, 8}, /* 1 Byte Out (144) */
    {0x2000, 0x92, 8}, /* 1 Byte Out (145) */
    {0x2000, 0x93, 8}, /* 1 Byte Out (146) */
    {0x2000, 0x94, 8}, /* 1 Byte Out (147) */
    {0x2000, 0x95, 8}, /* 1 Byte Out (148) */
    {0x2000, 0x96, 8}, /* 1 Byte Out (149) */
    {0x2000, 0x97, 8}, /* 1 Byte Out (150) */
    {0x2000, 0x98, 8}, /* 1 Byte Out (151) */
    {0x2000, 0x99, 8}, /* 1 Byte Out (152) */
    {0x2000, 0x9a, 8}, /* 1 Byte Out (153) */
    {0x2000, 0x9b, 8}, /* 1 Byte Out (154) */
    {0x2000, 0x9c, 8}, /* 1 Byte Out (155) */
    {0x2000, 0x9d, 8}, /* 1 Byte Out (156) */
    {0x2000, 0x9e, 8}, /* 1 Byte Out (157) */
    {0x2000, 0x9f, 8}, /* 1 Byte Out (158) */
    {0x2000, 0xa0, 8}, /* 1 Byte Out (159) */
    {0x2000, 0xa1, 8}, /* 1 Byte Out (160) */
    {0x2000, 0xa2, 8}, /* 1 Byte Out (161) */
    {0x2000, 0xa3, 8}, /* 1 Byte Out (162) */
    {0x2000, 0xa4, 8}, /* 1 Byte Out (163) */
    {0x2000, 0xa5, 8}, /* 1 Byte Out (164) */
    {0x2000, 0xa6, 8}, /* 1 Byte Out (165) */
    {0x2000, 0xa7, 8}, /* 1 Byte Out (166) */
    {0x2000, 0xa8, 8}, /* 1 Byte Out (167) */
    {0x2000, 0xa9, 8}, /* 1 Byte Out (168) */
    {0x2000, 0xaa, 8}, /* 1 Byte Out (169) */
    {0x2000, 0xab, 8}, /* 1 Byte Out (170) */
    {0x2000, 0xac, 8}, /* 1 Byte Out (171) */
    {0x2000, 0xad, 8}, /* 1 Byte Out (172) */
    {0x2000, 0xae, 8}, /* 1 Byte Out (173) */
    {0x2000, 0xaf, 8}, /* 1 Byte Out (174) */
    {0x2000, 0xb0, 8}, /* 1 Byte Out (175) */
    {0x2000, 0xb1, 8}, /* 1 Byte Out (176) */
    {0x2000, 0xb2, 8}, /* 1 Byte Out (177) */
    {0x2000, 0xb3, 8}, /* 1 Byte Out (178) */
    {0x2000, 0xb4, 8}, /* 1 Byte Out (179) */
    {0x2000, 0xb5, 8}, /* 1 Byte Out (180) */
    {0x2000, 0xb6, 8}, /* 1 Byte Out (181) */
    {0x2000, 0xb7, 8}, /* 1 Byte Out (182) */
    {0x2000, 0xb8, 8}, /* 1 Byte Out (183) */
    {0x2000, 0xb9, 8}, /* 1 Byte Out (184) */
    {0x2000, 0xba, 8}, /* 1 Byte Out (185) */
    {0x2000, 0xbb, 8}, /* 1 Byte Out (186) */
    {0x2000, 0xbc, 8}, /* 1 Byte Out (187) */
    {0x2000, 0xbd, 8}, /* 1 Byte Out (188) */
    {0x2000, 0xbe, 8}, /* 1 Byte Out (189) */
    {0x2000, 0xbf, 8}, /* 1 Byte Out (190) */
    {0x2000, 0xc0, 8}, /* 1 Byte Out (191) */
    {0x2000, 0xc1, 8}, /* 1 Byte Out (192) */
    {0x2000, 0xc2, 8}, /* 1 Byte Out (193) */
    {0x2000, 0xc3, 8}, /* 1 Byte Out (194) */
    {0x2000, 0xc4, 8}, /* 1 Byte Out (195) */
    {0x2000, 0xc5, 8}, /* 1 Byte Out (196) */
    {0x2000, 0xc6, 8}, /* 1 Byte Out (197) */
    {0x2000, 0xc7, 8}, /* 1 Byte Out (198) */
    {0x2000, 0xc8, 8}, /* 1 Byte Out (199) */
    {0x3000, 0x01, 8}, /* 1 Byte In (0) */
    {0x3000, 0x02, 8}, /* 1 Byte In (1) */
    {0x3000, 0x03, 8}, /* 1 Byte In (2) */
    {0x3000, 0x04, 8}, /* 1 Byte In (3) */
    {0x3000, 0x05, 8}, /* 1 Byte In (4) */
    {0x3000, 0x06, 8}, /* 1 Byte In (5) */
    {0x3000, 0x07, 8}, /* 1 Byte In (6) */
    {0x3000, 0x08, 8}, /* 1 Byte In (7) */
    {0x3000, 0x09, 8}, /* 1 Byte In (8) */
    {0x3000, 0x0a, 8}, /* 1 Byte In (9) */
    {0x3000, 0x0b, 8}, /* 1 Byte In (10) */
    {0x3000, 0x0c, 8}, /* 1 Byte In (11) */
    {0x3000, 0x0d, 8}, /* 1 Byte In (12) */
    {0x3000, 0x0e, 8}, /* 1 Byte In (13) */
    {0x3000, 0x0f, 8}, /* 1 Byte In (14) */
    {0x3000, 0x10, 8}, /* 1 Byte In (15) */
    {0x3000, 0x11, 8}, /* 1 Byte In (16) */
    {0x3000, 0x12, 8}, /* 1 Byte In (17) */
    {0x3000, 0x13, 8}, /* 1 Byte In (18) */
    {0x3000, 0x14, 8}, /* 1 Byte In (19) */
    {0x3000, 0x15, 8}, /* 1 Byte In (20) */
    {0x3000, 0x16, 8}, /* 1 Byte In (21) */
    {0x3000, 0x17, 8}, /* 1 Byte In (22) */
    {0x3000, 0x18, 8}, /* 1 Byte In (23) */
    {0x3000, 0x19, 8}, /* 1 Byte In (24) */
    {0x3000, 0x1a, 8}, /* 1 Byte In (25) */
    {0x3000, 0x1b, 8}, /* 1 Byte In (26) */
    {0x3000, 0x1c, 8}, /* 1 Byte In (27) */
    {0x3000, 0x1d, 8}, /* 1 Byte In (28) */
    {0x3000, 0x1e, 8}, /* 1 Byte In (29) */
    {0x3000, 0x1f, 8}, /* 1 Byte In (30) */
    {0x3000, 0x20, 8}, /* 1 Byte In (31) */
    {0x3000, 0x21, 8}, /* 1 Byte In (32) */
    {0x3000, 0x22, 8}, /* 1 Byte In (33) */
    {0x3000, 0x23, 8}, /* 1 Byte In (34) */
    {0x3000, 0x24, 8}, /* 1 Byte In (35) */
    {0x3000, 0x25, 8}, /* 1 Byte In (36) */
    {0x3000, 0x26, 8}, /* 1 Byte In (37) */
    {0x3000, 0x27, 8}, /* 1 Byte In (38) */
    {0x3000, 0x28, 8}, /* 1 Byte In (39) */
    {0x3000, 0x29, 8}, /* 1 Byte In (40) */
    {0x3000, 0x2a, 8}, /* 1 Byte In (41) */
    {0x3000, 0x2b, 8}, /* 1 Byte In (42) */
    {0x3000, 0x2c, 8}, /* 1 Byte In (43) */
    {0x3000, 0x2d, 8}, /* 1 Byte In (44) */
    {0x3000, 0x2e, 8}, /* 1 Byte In (45) */
    {0x3000, 0x2f, 8}, /* 1 Byte In (46) */
    {0x3000, 0x30, 8}, /* 1 Byte In (47) */
    {0x3000, 0x31, 8}, /* 1 Byte In (48) */
    {0x3000, 0x32, 8}, /* 1 Byte In (49) */
    {0x3000, 0x33, 8}, /* 1 Byte In (50) */
    {0x3000, 0x34, 8}, /* 1 Byte In (51) */
    {0x3000, 0x35, 8}, /* 1 Byte In (52) */
    {0x3000, 0x36, 8}, /* 1 Byte In (53) */
    {0x3000, 0x37, 8}, /* 1 Byte In (54) */
    {0x3000, 0x38, 8}, /* 1 Byte In (55) */
    {0x3000, 0x39, 8}, /* 1 Byte In (56) */
    {0x3000, 0x3a, 8}, /* 1 Byte In (57) */
    {0x3000, 0x3b, 8}, /* 1 Byte In (58) */
    {0x3000, 0x3c, 8}, /* 1 Byte In (59) */
    {0x3000, 0x3d, 8}, /* 1 Byte In (60) */
    {0x3000, 0x3e, 8}, /* 1 Byte In (61) */
    {0x3000, 0x3f, 8}, /* 1 Byte In (62) */
    {0x3000, 0x40, 8}, /* 1 Byte In (63) */
    {0x3000, 0x41, 8}, /* 1 Byte In (64) */
    {0x3000, 0x42, 8}, /* 1 Byte In (65) */
    {0x3000, 0x43, 8}, /* 1 Byte In (66) */
    {0x3000, 0x44, 8}, /* 1 Byte In (67) */
    {0x3000, 0x45, 8}, /* 1 Byte In (68) */
    {0x3000, 0x46, 8}, /* 1 Byte In (69) */
    {0x3000, 0x47, 8}, /* 1 Byte In (70) */
    {0x3000, 0x48, 8}, /* 1 Byte In (71) */
    {0x3000, 0x49, 8}, /* 1 Byte In (72) */
    {0x3000, 0x4a, 8}, /* 1 Byte In (73) */
    {0x3000, 0x4b, 8}, /* 1 Byte In (74) */
    {0x3000, 0x4c, 8}, /* 1 Byte In (75) */
    {0x3000, 0x4d, 8}, /* 1 Byte In (76) */
    {0x3000, 0x4e, 8}, /* 1 Byte In (77) */
    {0x3000, 0x4f, 8}, /* 1 Byte In (78) */
    {0x3000, 0x50, 8}, /* 1 Byte In (79) */
    {0x3000, 0x51, 8}, /* 1 Byte In (80) */
    {0x3000, 0x52, 8}, /* 1 Byte In (81) */
    {0x3000, 0x53, 8}, /* 1 Byte In (82) */
    {0x3000, 0x54, 8}, /* 1 Byte In (83) */
    {0x3000, 0x55, 8}, /* 1 Byte In (84) */
    {0x3000, 0x56, 8}, /* 1 Byte In (85) */
    {0x3000, 0x57, 8}, /* 1 Byte In (86) */
    {0x3000, 0x58, 8}, /* 1 Byte In (87) */
    {0x3000, 0x59, 8}, /* 1 Byte In (88) */
    {0x3000, 0x5a, 8}, /* 1 Byte In (89) */
    {0x3000, 0x5b, 8}, /* 1 Byte In (90) */
    {0x3000, 0x5c, 8}, /* 1 Byte In (91) */
    {0x3000, 0x5d, 8}, /* 1 Byte In (92) */
    {0x3000, 0x5e, 8}, /* 1 Byte In (93) */
    {0x3000, 0x5f, 8}, /* 1 Byte In (94) */
    {0x3000, 0x60, 8}, /* 1 Byte In (95) */
    {0x3000, 0x61, 8}, /* 1 Byte In (96) */
    {0x3000, 0x62, 8}, /* 1 Byte In (97) */
    {0x3000, 0x63, 8}, /* 1 Byte In (98) */
    {0x3000, 0x64, 8}, /* 1 Byte In (99) */
    {0x3000, 0x65, 8}, /* 1 Byte In (100) */
    {0x3000, 0x66, 8}, /* 1 Byte In (101) */
    {0x3000, 0x67, 8}, /* 1 Byte In (102) */
    {0x3000, 0x68, 8}, /* 1 Byte In (103) */
    {0x3000, 0x69, 8}, /* 1 Byte In (104) */
    {0x3000, 0x6a, 8}, /* 1 Byte In (105) */
    {0x3000, 0x6b, 8}, /* 1 Byte In (106) */
    {0x3000, 0x6c, 8}, /* 1 Byte In (107) */
    {0x3000, 0x6d, 8}, /* 1 Byte In (108) */
    {0x3000, 0x6e, 8}, /* 1 Byte In (109) */
    {0x3000, 0x6f, 8}, /* 1 Byte In (110) */
    {0x3000, 0x70, 8}, /* 1 Byte In (111) */
    {0x3000, 0x71, 8}, /* 1 Byte In (112) */
    {0x3000, 0x72, 8}, /* 1 Byte In (113) */
    {0x3000, 0x73, 8}, /* 1 Byte In (114) */
    {0x3000, 0x74, 8}, /* 1 Byte In (115) */
    {0x3000, 0x75, 8}, /* 1 Byte In (116) */
    {0x3000, 0x76, 8}, /* 1 Byte In (117) */
    {0x3000, 0x77, 8}, /* 1 Byte In (118) */
    {0x3000, 0x78, 8}, /* 1 Byte In (119) */
    {0x3000, 0x79, 8}, /* 1 Byte In (120) */
    {0x3000, 0x7a, 8}, /* 1 Byte In (121) */
    {0x3000, 0x7b, 8}, /* 1 Byte In (122) */
    {0x3000, 0x7c, 8}, /* 1 Byte In (123) */
    {0x3000, 0x7d, 8}, /* 1 Byte In (124) */
    {0x3000, 0x7e, 8}, /* 1 Byte In (125) */
    {0x3000, 0x7f, 8}, /* 1 Byte In (126) */
    {0x3000, 0x80, 8}, /* 1 Byte In (127) */
    {0x3000, 0x81, 8}, /* 1 Byte In (128) */
    {0x3000, 0x82, 8}, /* 1 Byte In (129) */
    {0x3000, 0x83, 8}, /* 1 Byte In (130) */
    {0x3000, 0x84, 8}, /* 1 Byte In (131) */
    {0x3000, 0x85, 8}, /* 1 Byte In (132) */
    {0x3000, 0x86, 8}, /* 1 Byte In (133) */
    {0x3000, 0x87, 8}, /* 1 Byte In (134) */
    {0x3000, 0x88, 8}, /* 1 Byte In (135) */
    {0x3000, 0x89, 8}, /* 1 Byte In (136) */
    {0x3000, 0x8a, 8}, /* 1 Byte In (137) */
    {0x3000, 0x8b, 8}, /* 1 Byte In (138) */
    {0x3000, 0x8c, 8}, /* 1 Byte In (139) */
    {0x3000, 0x8d, 8}, /* 1 Byte In (140) */
    {0x3000, 0x8e, 8}, /* 1 Byte In (141) */
    {0x3000, 0x8f, 8}, /* 1 Byte In (142) */
    {0x3000, 0x90, 8}, /* 1 Byte In (143) */
    {0x3000, 0x91, 8}, /* 1 Byte In (144) */
    {0x3000, 0x92, 8}, /* 1 Byte In (145) */
    {0x3000, 0x93, 8}, /* 1 Byte In (146) */
    {0x3000, 0x94, 8}, /* 1 Byte In (147) */
    {0x3000, 0x95, 8}, /* 1 Byte In (148) */
    {0x3000, 0x96, 8}, /* 1 Byte In (149) */
    {0x3000, 0x97, 8}, /* 1 Byte In (150) */
    {0x3000, 0x98, 8}, /* 1 Byte In (151) */
    {0x3000, 0x99, 8}, /* 1 Byte In (152) */
    {0x3000, 0x9a, 8}, /* 1 Byte In (153) */
    {0x3000, 0x9b, 8}, /* 1 Byte In (154) */
    {0x3000, 0x9c, 8}, /* 1 Byte In (155) */
    {0x3000, 0x9d, 8}, /* 1 Byte In (156) */
    {0x3000, 0x9e, 8}, /* 1 Byte In (157) */
    {0x3000, 0x9f, 8}, /* 1 Byte In (158) */
    {0x3000, 0xa0, 8}, /* 1 Byte In (159) */
    {0x3000, 0xa1, 8}, /* 1 Byte In (160) */
    {0x3000, 0xa2, 8}, /* 1 Byte In (161) */
    {0x3000, 0xa3, 8}, /* 1 Byte In (162) */
    {0x3000, 0xa4, 8}, /* 1 Byte In (163) */
    {0x3000, 0xa5, 8}, /* 1 Byte In (164) */
    {0x3000, 0xa6, 8}, /* 1 Byte In (165) */
    {0x3000, 0xa7, 8}, /* 1 Byte In (166) */
    {0x3000, 0xa8, 8}, /* 1 Byte In (167) */
    {0x3000, 0xa9, 8}, /* 1 Byte In (168) */
    {0x3000, 0xaa, 8}, /* 1 Byte In (169) */
    {0x3000, 0xab, 8}, /* 1 Byte In (170) */
    {0x3000, 0xac, 8}, /* 1 Byte In (171) */
    {0x3000, 0xad, 8}, /* 1 Byte In (172) */
    {0x3000, 0xae, 8}, /* 1 Byte In (173) */
    {0x3000, 0xaf, 8}, /* 1 Byte In (174) */
    {0x3000, 0xb0, 8}, /* 1 Byte In (175) */
    {0x3000, 0xb1, 8}, /* 1 Byte In (176) */
    {0x3000, 0xb2, 8}, /* 1 Byte In (177) */
    {0x3000, 0xb3, 8}, /* 1 Byte In (178) */
    {0x3000, 0xb4, 8}, /* 1 Byte In (179) */
    {0x3000, 0xb5, 8}, /* 1 Byte In (180) */
    {0x3000, 0xb6, 8}, /* 1 Byte In (181) */
    {0x3000, 0xb7, 8}, /* 1 Byte In (182) */
    {0x3000, 0xb8, 8}, /* 1 Byte In (183) */
    {0x3000, 0xb9, 8}, /* 1 Byte In (184) */
    {0x3000, 0xba, 8}, /* 1 Byte In (185) */
    {0x3000, 0xbb, 8}, /* 1 Byte In (186) */
    {0x3000, 0xbc, 8}, /* 1 Byte In (187) */
    {0x3000, 0xbd, 8}, /* 1 Byte In (188) */
    {0x3000, 0xbe, 8}, /* 1 Byte In (189) */
    {0x3000, 0xbf, 8}, /* 1 Byte In (190) */
    {0x3000, 0xc0, 8}, /* 1 Byte In (191) */
    {0x3000, 0xc1, 8}, /* 1 Byte In (192) */
    {0x3000, 0xc2, 8}, /* 1 Byte In (193) */
    {0x3000, 0xc3, 8}, /* 1 Byte In (194) */
    {0x3000, 0xc4, 8}, /* 1 Byte In (195) */
    {0x3000, 0xc5, 8}, /* 1 Byte In (196) */
    {0x3000, 0xc6, 8}, /* 1 Byte In (197) */
    {0x3000, 0xc7, 8}, /* 1 Byte In (198) */
    {0x3000, 0xc8, 8}, /* 1 Byte In (199) */
};

ec_pdo_info_t slave_0_pdos[] = {
    {0x1600, 200, slave_0_pdo_entries + 0}, /* 1. RxPDO */
    {0x1a00, 200, slave_0_pdo_entries + 200}, /* 1. TxPDO */
};

ec_sync_info_t slave_0_syncs[] = {
    {0, EC_DIR_OUTPUT, 0, NULL, EC_WD_DISABLE},
    {1, EC_DIR_INPUT, 0, NULL, EC_WD_DISABLE},
    {2, EC_DIR_OUTPUT, 1, slave_0_pdos + 0, EC_WD_ENABLE},
    {3, EC_DIR_INPUT, 1, slave_0_pdos + 1, EC_WD_DISABLE},
    {0xff}
};




// offsets for PDO entries
static uint32_t input[200];
static uint32_t output[200];
uint8_t input_data[200];
uint8_t output_data[200];
/* output data */
const static ec_pdo_entry_reg_t domain1_regs[] = {	
	PDO_OU_REG(1)
	PDO_OU_REG(2)
	PDO_OU_REG(3)
	PDO_OU_REG(4)
	PDO_OU_REG(5)
	PDO_OU_REG(6)
	PDO_OU_REG(7)
	PDO_OU_REG(8)
	PDO_OU_REG(9)
	PDO_OU_REG(10)	
	PDO_OU_REG(11)
	PDO_OU_REG(12)
	PDO_OU_REG(13)
	PDO_OU_REG(14)
	PDO_OU_REG(15)
	PDO_OU_REG(16)
	PDO_OU_REG(17)
	PDO_OU_REG(18)
	PDO_OU_REG(19)
	PDO_OU_REG(20)
	PDO_OU_REG(21)
	PDO_OU_REG(22)
	PDO_OU_REG(23)
	PDO_OU_REG(24)
	PDO_OU_REG(25)
	PDO_OU_REG(26)
	PDO_OU_REG(27)
	PDO_OU_REG(28)
	PDO_OU_REG(29)
	PDO_OU_REG(30)	
	PDO_OU_REG(31)
	PDO_OU_REG(32)
	PDO_OU_REG(33)
	PDO_OU_REG(34)
	PDO_OU_REG(35)
	PDO_OU_REG(36)
	PDO_OU_REG(37)
	PDO_OU_REG(38)
	PDO_OU_REG(39)
	PDO_OU_REG(40)
	PDO_OU_REG(41)
	PDO_OU_REG(42)
	PDO_OU_REG(43)
	PDO_OU_REG(44)
	PDO_OU_REG(45)
	PDO_OU_REG(46)
	PDO_OU_REG(47)
	PDO_OU_REG(48)
	PDO_OU_REG(49)
	PDO_OU_REG(50)	
	PDO_OU_REG(51)
	PDO_OU_REG(52)
	PDO_OU_REG(53)
	PDO_OU_REG(54)
	PDO_OU_REG(55)
	PDO_OU_REG(56)
	PDO_OU_REG(57)
	PDO_OU_REG(58)
	PDO_OU_REG(59)
	PDO_OU_REG(60)
	PDO_OU_REG(61)
	PDO_OU_REG(62)
	PDO_OU_REG(63)
	PDO_OU_REG(64)
	PDO_OU_REG(65)
	PDO_OU_REG(66)
	PDO_OU_REG(67)
	PDO_OU_REG(68)
	PDO_OU_REG(69)
	PDO_OU_REG(70)	
	PDO_OU_REG(71)
	PDO_OU_REG(72)
	PDO_OU_REG(73)
	PDO_OU_REG(74)
	PDO_OU_REG(75)
	PDO_OU_REG(76)
	PDO_OU_REG(77)
	PDO_OU_REG(78)
	PDO_OU_REG(79)
	PDO_OU_REG(80)
	PDO_OU_REG(81)
	PDO_OU_REG(82)
	PDO_OU_REG(83)
	PDO_OU_REG(84)
	PDO_OU_REG(85)
	PDO_OU_REG(86)
	PDO_OU_REG(87)
	PDO_OU_REG(88)
	PDO_OU_REG(89)
	PDO_OU_REG(90)	
	PDO_OU_REG(91)
	PDO_OU_REG(92)
	PDO_OU_REG(93)
	PDO_OU_REG(94)
	PDO_OU_REG(95)
	PDO_OU_REG(96)
	PDO_OU_REG(97)
	PDO_OU_REG(98)
	PDO_OU_REG(99)
	PDO_OU_REG(100)
	PDO_OU_REG(101)
	PDO_OU_REG(102)
	PDO_OU_REG(103)
	PDO_OU_REG(104)
	PDO_OU_REG(105)
	PDO_OU_REG(106)
	PDO_OU_REG(107)
	PDO_OU_REG(108)
	PDO_OU_REG(109)
	PDO_OU_REG(110)	
	PDO_OU_REG(111)
	PDO_OU_REG(112)
	PDO_OU_REG(113)
	PDO_OU_REG(114)
	PDO_OU_REG(115)
	PDO_OU_REG(116)
	PDO_OU_REG(117)
	PDO_OU_REG(118)
	PDO_OU_REG(119)
	PDO_OU_REG(120)
	PDO_OU_REG(121)
	PDO_OU_REG(122)
	PDO_OU_REG(123)
	PDO_OU_REG(124)
	PDO_OU_REG(125)
	PDO_OU_REG(126)
	PDO_OU_REG(127)
	PDO_OU_REG(128)
	PDO_OU_REG(129)
	PDO_OU_REG(130)	
	PDO_OU_REG(131)
	PDO_OU_REG(132)
	PDO_OU_REG(133)
	PDO_OU_REG(134)
	PDO_OU_REG(135)
	PDO_OU_REG(136)
	PDO_OU_REG(137)
	PDO_OU_REG(138)
	PDO_OU_REG(139)
	PDO_OU_REG(140)
	PDO_OU_REG(141)
	PDO_OU_REG(142)
	PDO_OU_REG(143)
	PDO_OU_REG(144)
	PDO_OU_REG(145)
	PDO_OU_REG(146)
	PDO_OU_REG(147)
	PDO_OU_REG(148)
	PDO_OU_REG(149)
	PDO_OU_REG(150)	
	PDO_OU_REG(151)
	PDO_OU_REG(152)
	PDO_OU_REG(153)
	PDO_OU_REG(154)
	PDO_OU_REG(155)
	PDO_OU_REG(156)
	PDO_OU_REG(157)
	PDO_OU_REG(158)
	PDO_OU_REG(159)
	PDO_OU_REG(160)
	PDO_OU_REG(161)
	PDO_OU_REG(162)
	PDO_OU_REG(163)
	PDO_OU_REG(164)
	PDO_OU_REG(165)
	PDO_OU_REG(166)
	PDO_OU_REG(167)
	PDO_OU_REG(168)
	PDO_OU_REG(169)
	PDO_OU_REG(170)	
	PDO_OU_REG(171)
	PDO_OU_REG(172)
	PDO_OU_REG(173)
	PDO_OU_REG(174)
	PDO_OU_REG(175)
	PDO_OU_REG(176)
	PDO_OU_REG(177)
	PDO_OU_REG(178)
	PDO_OU_REG(179)
	PDO_OU_REG(180)
	PDO_OU_REG(181)
	PDO_OU_REG(182)
	PDO_OU_REG(183)
	PDO_OU_REG(184)
	PDO_OU_REG(185)
	PDO_OU_REG(186)
	PDO_OU_REG(187)
	PDO_OU_REG(188)
	PDO_OU_REG(189)
	PDO_OU_REG(190)	
	PDO_OU_REG(191)
	PDO_OU_REG(192)
	PDO_OU_REG(193)
	PDO_OU_REG(194)
	PDO_OU_REG(195)
	PDO_OU_REG(196)
	PDO_OU_REG(197)
	PDO_OU_REG(198)
	PDO_OU_REG(199)
	PDO_OU_REG(200)
	{}
};

/* inut data */
const static ec_pdo_entry_reg_t domain2_regs[] = {
	PDO_IN_REG(1)
	PDO_IN_REG(2)
	PDO_IN_REG(3)
	PDO_IN_REG(4)
	PDO_IN_REG(5)
	PDO_IN_REG(6)
	PDO_IN_REG(7)
	PDO_IN_REG(8)
	PDO_IN_REG(9)
	PDO_IN_REG(10)	
	PDO_IN_REG(11)
	PDO_IN_REG(12)
	PDO_IN_REG(13)
	PDO_IN_REG(14)
	PDO_IN_REG(15)
	PDO_IN_REG(16)
	PDO_IN_REG(17)
	PDO_IN_REG(18)
	PDO_IN_REG(19)
	PDO_IN_REG(20)
	PDO_IN_REG(21)
	PDO_IN_REG(22)
	PDO_IN_REG(23)
	PDO_IN_REG(24)
	PDO_IN_REG(25)
	PDO_IN_REG(26)
	PDO_IN_REG(27)
	PDO_IN_REG(28)
	PDO_IN_REG(29)
	PDO_IN_REG(30)	
	PDO_IN_REG(31)
	PDO_IN_REG(32)
	PDO_IN_REG(33)
	PDO_IN_REG(34)
	PDO_IN_REG(35)
	PDO_IN_REG(36)
	PDO_IN_REG(37)
	PDO_IN_REG(38)
	PDO_IN_REG(39)
	PDO_IN_REG(40)
	PDO_IN_REG(41)
	PDO_IN_REG(42)
	PDO_IN_REG(43)
	PDO_IN_REG(44)
	PDO_IN_REG(45)
	PDO_IN_REG(46)
	PDO_IN_REG(47)
	PDO_IN_REG(48)
	PDO_IN_REG(49)
	PDO_IN_REG(50)	
	PDO_IN_REG(51)
	PDO_IN_REG(52)
	PDO_IN_REG(53)
	PDO_IN_REG(54)
	PDO_IN_REG(55)
	PDO_IN_REG(56)
	PDO_IN_REG(57)
	PDO_IN_REG(58)
	PDO_IN_REG(59)
	PDO_IN_REG(60)
	PDO_IN_REG(61)
	PDO_IN_REG(62)
	PDO_IN_REG(63)
	PDO_IN_REG(64)
	PDO_IN_REG(65)
	PDO_IN_REG(66)
	PDO_IN_REG(67)
	PDO_IN_REG(68)
	PDO_IN_REG(69)
	PDO_IN_REG(70)	
	PDO_IN_REG(71)
	PDO_IN_REG(72)
	PDO_IN_REG(73)
	PDO_IN_REG(74)
	PDO_IN_REG(75)
	PDO_IN_REG(76)
	PDO_IN_REG(77)
	PDO_IN_REG(78)
	PDO_IN_REG(79)
	PDO_IN_REG(80)
	PDO_IN_REG(81)
	PDO_IN_REG(82)
	PDO_IN_REG(83)
	PDO_IN_REG(84)
	PDO_IN_REG(85)
	PDO_IN_REG(86)
	PDO_IN_REG(87)
	PDO_IN_REG(88)
	PDO_IN_REG(89)
	PDO_IN_REG(90)	
	PDO_IN_REG(91)
	PDO_IN_REG(92)
	PDO_IN_REG(93)
	PDO_IN_REG(94)
	PDO_IN_REG(95)
	PDO_IN_REG(96)
	PDO_IN_REG(97)
	PDO_IN_REG(98)
	PDO_IN_REG(99)
	PDO_IN_REG(100)
	PDO_IN_REG(101)
	PDO_IN_REG(102)
	PDO_IN_REG(103)
	PDO_IN_REG(104)
	PDO_IN_REG(105)
	PDO_IN_REG(106)
	PDO_IN_REG(107)
	PDO_IN_REG(108)
	PDO_IN_REG(109)
	PDO_IN_REG(110)	
	PDO_IN_REG(111)
	PDO_IN_REG(112)
	PDO_IN_REG(113)
	PDO_IN_REG(114)
	PDO_IN_REG(115)
	PDO_IN_REG(116)
	PDO_IN_REG(117)
	PDO_IN_REG(118)
	PDO_IN_REG(119)
	PDO_IN_REG(120)
	PDO_IN_REG(121)
	PDO_IN_REG(122)
	PDO_IN_REG(123)
	PDO_IN_REG(124)
	PDO_IN_REG(125)
	PDO_IN_REG(126)
	PDO_IN_REG(127)
	PDO_IN_REG(128)
	PDO_IN_REG(129)
	PDO_IN_REG(130)	
	PDO_IN_REG(131)
	PDO_IN_REG(132)
	PDO_IN_REG(133)
	PDO_IN_REG(134)
	PDO_IN_REG(135)
	PDO_IN_REG(136)
	PDO_IN_REG(137)
	PDO_IN_REG(138)
	PDO_IN_REG(139)
	PDO_IN_REG(140)
	PDO_IN_REG(141)
	PDO_IN_REG(142)
	PDO_IN_REG(143)
	PDO_IN_REG(144)
	PDO_IN_REG(145)
	PDO_IN_REG(146)
	PDO_IN_REG(147)
	PDO_IN_REG(148)
	PDO_IN_REG(149)
	PDO_IN_REG(150)	
	PDO_IN_REG(151)
	PDO_IN_REG(152)
	PDO_IN_REG(153)
	PDO_IN_REG(154)
	PDO_IN_REG(155)
	PDO_IN_REG(156)
	PDO_IN_REG(157)
	PDO_IN_REG(158)
	PDO_IN_REG(159)
	PDO_IN_REG(160)
	PDO_IN_REG(161)
	PDO_IN_REG(162)
	PDO_IN_REG(163)
	PDO_IN_REG(164)
	PDO_IN_REG(165)
	PDO_IN_REG(166)
	PDO_IN_REG(167)
	PDO_IN_REG(168)
	PDO_IN_REG(169)
	PDO_IN_REG(170)	
	PDO_IN_REG(171)
	PDO_IN_REG(172)
	PDO_IN_REG(173)
	PDO_IN_REG(174)
	PDO_IN_REG(175)
	PDO_IN_REG(176)
	PDO_IN_REG(177)
	PDO_IN_REG(178)
	PDO_IN_REG(179)
	PDO_IN_REG(180)
	PDO_IN_REG(181)
	PDO_IN_REG(182)
	PDO_IN_REG(183)
	PDO_IN_REG(184)
	PDO_IN_REG(185)
	PDO_IN_REG(186)
	PDO_IN_REG(187)
	PDO_IN_REG(188)
	PDO_IN_REG(189)
	PDO_IN_REG(190)	
	PDO_IN_REG(191)
	PDO_IN_REG(192)
	PDO_IN_REG(193)
	PDO_IN_REG(194)
	PDO_IN_REG(195)
	PDO_IN_REG(196)
	PDO_IN_REG(197)
	PDO_IN_REG(198)
	PDO_IN_REG(199)
	PDO_IN_REG(200)
	{}
};

static unsigned int counter = 0;
static unsigned int blink = 0;

/*****************************************************************************/



/*****************************************************************************/

void check_domain1_state(void)
{
    ec_domain_state_t ds;

    ecrt_domain_state(domain1, &ds);

    if (ds.working_counter != domain1_state.working_counter) {
        printf("Domain1: WC %u.\n", ds.working_counter);
    }
    if (ds.wc_state != domain1_state.wc_state) {
        printf("Domain1: State %u.\n", ds.wc_state);
    }

    domain1_state = ds;
}

/*****************************************************************************/

void check_master_state(void)
{
    ec_master_state_t ms;

    ecrt_master_state(master, &ms);

    if (ms.slaves_responding != master_state.slaves_responding) {
        printf("%u slave(s).\n", ms.slaves_responding);
    }
    if (ms.al_states != master_state.al_states) {
        printf("AL states: 0x%02X.\n", ms.al_states);
    }
    if (ms.link_up != master_state.link_up) {
        printf("Link is %s.\n", ms.link_up ? "up" : "down");
    }

    master_state = ms;
}

/*****************************************************************************/

void check_slave_config_states(void)
{
    ec_slave_config_state_t s;

    ecrt_slave_config_state(cifxecs, &s);

    if (s.al_state != cifxecs_state.al_state) {
        printf("AnaIn: State 0x%02X.\n", s.al_state);
    }
    if (s.online != cifxecs_state.online) {
        printf("AnaIn: %s.\n", s.online ? "online" : "offline");
    }
    if (s.operational !=cifxecs_state.operational) {
        printf("AnaIn: %soperational.\n", s.operational ? "" : "Not ");
    }

    cifxecs_state = s;
}

/*****************************************************************************/

void cyclic_task()
{
	int32_t i=0;
	uint8_t temp;
	int fail = 0;
	// receive process data
	ecrt_master_receive(master);
    ecrt_domain_process(domain1);
	ecrt_domain_process(domain2);

	ecrt_domain_state(domain1, &domain1_state);
	ecrt_domain_state(domain2, &domain2_state);
	ecrt_master_state(master, &master_state);

	

	if(domain2_state.wc_state == EC_WC_COMPLETE && master_state.al_states == 0x08) {
    	// read process data
		for (i=0;i<200;i++) {
			output_data[i]++;
			temp =  EC_READ_U8(domain2_pd + input[i]);
			input_data[i] = temp;
			if (input_data[i] != output_data[i]) {
				fail++;
			}
			printf("recv = %.3d fail = %4.d \n", temp, fail);
		}
	} else {
		printf("\n domain1 fails ============================\n");
		printf("domain1.wc_state=%d domain2.wc_state=%d\n",domain1_state.wc_state ,domain2_state.wc_state);	
	}

	if(domain1_state.wc_state == EC_WC_COMPLETE && master_state.al_states == 0x08) {
    	// read process data
		for (i=0;i<200;i++) {
			output_data[i] = input_data[i]+1;
			EC_WRITE_U8(domain1_pd + output[i], output_data[i]);
		}
	} else {
		printf("\n domain1 fails ============================\n");
		printf("domain1.wc_state=%d domain2.wc_state=%d\n",domain1_state.wc_state ,domain2_state.wc_state);	
	}


    // send process data
    ecrt_domain_queue(domain1);
	ecrt_domain_queue(domain2);
    ecrt_master_send(master);
}

void spin_config(){
	ecrt_master_receive(master);
    ecrt_domain_process(domain1);
	
	ecrt_domain_state(domain1, &domain1_state);
	ecrt_master_state(master, &master_state);

	if(domain1_state.wc_state == EC_WC_COMPLETE &&
		master_state.al_states == 0x08) {
		printf("slave config complete!\n");
		return ;
	}
	ecrt_domain_queue(domain1);
    ecrt_master_send(master);
}
/****************************************************************************/




void stack_prefault(void)
{
    unsigned char dummy[MAX_SAFE_STACK];

    memset(dummy, 0, MAX_SAFE_STACK);
}

/****************************************************************************/

int main(int argc, char **argv)
{
    ec_slave_config_t *sc;
    struct timespec wakeup_time;
    int ret = 0;

	ec_slave_info_t slave_info;
	uint16_t slave_position = 0;

	// request master
    master = ecrt_request_master(0);
    if (!master) {
        return -1;
    }

	// acquire domain
    domain1 = ecrt_master_create_domain(master);
    if (!domain1) {
        return -1;
    }

	domain2 = ecrt_master_create_domain(master);
    if (!domain2) {
        return -1;
    }

	// get slave configuration one for each slave
    if (!(cifxecs = ecrt_master_slave_config(
                    master, CIFXECS_POS, CIFXECS_CARD))) {
        fprintf(stderr, "Failed to get slave configuration.\n");
        return -1;
    }
	
	// config Pdos, ec_sync_info_t used here, one for each slave
    printf("Configuring PDOs...\n");
    if (ecrt_slave_config_pdos(cifxecs, EC_END, slave_0_syncs)) {
        fprintf(stderr, "Failed to configure PDOs.\n");
        return -1;
    }

	// set PDO regs ec_pdo_entry_reg_t is used heer, once per domain
    if (ecrt_domain_reg_pdo_entry_list(domain1, domain1_regs)) {
        fprintf(stderr, "PDO entry registration failed!\n");
        return -1;
    }

	if (ecrt_domain_reg_pdo_entry_list(domain2, domain2_regs)) {
        fprintf(stderr, "PDO entry registration failed!\n");
        return -1;
    }
	// active master
    printf("Activating master...\n");
    if (ecrt_master_activate(master)) {
        return -1;
    }
	
	//acquire domain memory mapping pointer
    if (!(domain1_pd = ecrt_domain_data(domain1))) {
        return -1;
    }
	
	if (!(domain2_pd = ecrt_domain_data(domain2))) {
        return -1;
    }
    /* Set priority */

    struct sched_param param = {};
    param.sched_priority = sched_get_priority_max(SCHED_FIFO);

    printf("Using priority %i.", param.sched_priority);
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler failed");
    }

    /* Lock memory */
    if (mlockall(MCL_CURRENT | MCL_FUTURE) == -1) {
        fprintf(stderr, "Warning: Failed to lock memory: %s\n",
                strerror(errno));
    }

    stack_prefault();
    printf("Starting RT task with dt=%u ns.\n", PERIOD_NS);

    clock_gettime(CLOCK_MONOTONIC, &wakeup_time);
    wakeup_time.tv_sec += 0; /* start in future */
    wakeup_time.tv_nsec = 1;

	/* wait to OP mode */
	while (1) {
		ret = clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME,
                &wakeup_time, NULL);

        ecrt_master_receive(master);
    	ecrt_domain_process(domain1);
		ecrt_domain_process(domain2);

		ecrt_domain_state(domain1, &domain1_state);
		ecrt_domain_state(domain2, &domain2_state);
		ecrt_master_state(master, &master_state);

		if(domain1_state.wc_state == EC_WC_COMPLETE && domain2_state.wc_state == EC_WC_COMPLETE ) {
			printf("wc_sate OK\n");
			if (master_state.al_states == 0x08) {
				break ;
			}
		}

		printf("wakeup_time = %.8lu nsec wc_state = %d\n",wakeup_time.tv_nsec ,domain1_state.wc_state);
		ecrt_domain_queue(domain1);
		ecrt_domain_queue(domain2);
    	ecrt_master_send(master);
		
		wakeup_time.tv_nsec += PERIOD_NS;
        while (wakeup_time.tv_nsec >= NSEC_PER_SEC) {
            wakeup_time.tv_nsec -= NSEC_PER_SEC;
            wakeup_time.tv_sec++;
        }
    }
	printf("slave config complete!\n");
	memset(input_data,  0, 200);
	memset(output_data, 0, 200);
    while (1) {
		
        ret = clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME,
                &wakeup_time, NULL);
        if (ret) {
            fprintf(stderr, "clock_nanosleep(): %s\n", strerror(ret));
            break;
        }
		
        cyclic_task();

        wakeup_time.tv_nsec += PERIOD_NS*25;
        while (wakeup_time.tv_nsec >= NSEC_PER_SEC) {
            wakeup_time.tv_nsec -= NSEC_PER_SEC;
            wakeup_time.tv_sec++;
        }
    }

    return ret;
}

/****************************************************************************/
