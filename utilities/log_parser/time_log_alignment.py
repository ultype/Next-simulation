#!/usr/bin/env python
import csv
import itertools
import sys
import re
def main():
    if len(sys.argv) > 0:
        log_nspo_csv_name = sys.argv[1]

    input_gpsr_s_nav_fileobj = open('gpsr_s_nav_tlm.csv', "rt", encoding="utf-8")
    input_dm_nspo_fileobj = open(log_nspo_csv_name, "rt", encoding="utf-8")
    output_time_compare_fileobj = open('refine_log_nspo.csv', 'w')
    csvCursor = csv.writer(output_time_compare_fileobj)

    sim_data_list = []

    gpsr_s_nav_arr = csv.reader(input_gpsr_s_nav_fileobj)
    dm_arr = csv.reader(input_dm_nspo_fileobj)

    cache_idx = 0
    for gpsr_elem in enumerate(gpsr_s_nav_arr):
        if gpsr_elem[0] == 0:
            continue;
        for dm_elem in enumerate(dm_arr , start = cache_idx):
            cache_idx = dm_elem[0]
            if dm_elem[0] == 0:
                csvCursor.writerow(dm_elem[1])
                continue;
            if abs(float(gpsr_elem[1][0]) - float(dm_elem[1][1])) < 1e-4:
                csvCursor.writerow(dm_elem[1])
                print (dm_elem[1])
                break

    input_dm_nspo_fileobj.close()
    input_gpsr_s_nav_fileobj.close()
    print ("refine_log_nspo.csv\n")
    print ("Next step ./combine_result_dm_and_gpsr_log.py <liftoff_time> <egse_1khz | dm_golden | rt200hz | ' '> ")

if __name__ == "__main__":
    main()
