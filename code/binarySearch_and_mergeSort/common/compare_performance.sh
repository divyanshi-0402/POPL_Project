#!/bin/bash
# Run `commands` with `tests` inputs `N` times each, and average the runtime of
# each command for each test Use `timetool` to measure the time elapsed

set -e
# number of runs to average the performance
N=10

commands=( ./main_cpp ./main_rust )
tests=( inp_low inp_mid inp_hi )
timetool=../common/measure/target/release/measure
tmp_file="./tmp.file"

echo "Averaging performance of $N runs.."
for command in "${commands[@]}"
do
    echo "$command:"
    for test in "${tests[@]}"
    do
        runtime_total=0.0
        core_total=0.0
        for try in $(seq 1 $N)
        do
            runtime=$( $timetool $command $test 2> ${tmp_file})
            runtime_total=$( awk "BEGIN { printf \"%.5f\", $runtime + $runtime_total }" )
            core_total=$( awk "BEGIN { printf \"%.5f\", $( cat ${tmp_file} ) + $core_total }" )
        done
        average_runtime=$( awk "BEGIN { printf \"%.5f\", $runtime_total / $N }" )
        average_core=$( awk "BEGIN { printf \"%.5f\", $core_total / $N }" )
        echo "  test $test: runtime $average_runtime sec, core ${average_core} sec"
    done
    echo ""
done