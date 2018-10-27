#!/bin/bash

SCRIPT_FILE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
SIM_HOME_PATH=$(echo $SCRIPT_FILE_DIR | sed 's/\/exe\/SIL\/master//g')
S_DEFINE_PATH=$SCRIPT_FILE_DIR
source $SIM_HOME_PATH/exe/xil_common/script/color_text.sh
set -e
cd $S_DEFINE_PATH
trick-CP
echo -e "${ORANGE} [Sirius] Please trigger the FSW manually...${NC}"
./S_main_Linux_*_x86_64.exe RUN_golden/golden.cpp

python $SIM_HOME_PATH/utilities/generate_error.py $SIM_HOME_PATH/tables/golden_answer/golden.csv $S_DEFINE_PATH/RUN_golden/log_rocket_csv.csv -l
python $SIM_HOME_PATH/utilities/ci_test.py $S_DEFINE_PATH/result.csv 1e-5 | tee test_result


# Test the exit status of the command before pipe
test ${PIPESTATUS[0]} -eq 0
