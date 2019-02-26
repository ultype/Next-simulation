/*******************************************************************************
 *
 *   Copyright (c) Hilscher GmbH. All Rights Reserved.
 *
 *******************************************************************************

 Filename:
 $Workfile: libsdpm.h $
 Last Modification:
 $Author: frankmeisenbach $
 $Modtime: 13.07.2015 12:00 $
 $Revision: 1 $

 Targets:
 Linux : yes

 Platform:

 Description:
 Header file for the libsdpm library.

 Changes:

 Version   Date        Author   Description
 -------------------------------------------------------------------------------
 1        13.07.2015   FM       - Initial Version (based on spi_sample.c)

 ******************************************************************************/

/******************************************************************************/
/*! Initializes a cifX device for SDPM (usage of SPI).
 *   \param pszSPIDevice  Name of spidev device file (optional)
 *   \param bMode         SPI mode
 *   \param bBits         Bits per SPI word
 *   \param ulFrequency   SPI frequency
 *   \param pszIRQFile    Name of IRQ trigger file (optional)
 *   \return  Pointer to initialized cifX device on success
 *            NULL on error                                                   */
/******************************************************************************/
struct CIFX_DEVICE_T* SDPMInit(uint8_t *pszSPIDevice, uint8_t bMode, uint8_t bBits, uint32_t ulFrequency, uint8_t *pszIRQFile, uint32_t ulChunkSize);
