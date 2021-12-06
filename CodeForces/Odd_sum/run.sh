#! /bin/zsh

dir_name=${PWD##*/}
arg="$1"
gen_in="${2:-gen_in}"
gen_out="${3:-gen_out}"

if [[ $arg = "gen_test" ]]
then
    n_testcase=100
    echo "Generating test cases..."
    g++ -std=c++14 -o $gen_in $gen_in.cpp
    g++ -std=c++14 -o $gen_out $gen_out.cpp

    ./$gen_in $n_testcase > input.txt
    ./$gen_out < input.txt > expected.txt
elif [[ $arg = "submit" ]]
then
    echo "Submiting..."
    git add input.txt solution.cpp output.txt
    git commit -m "$dir_name: solved"
    git push
    echo "Submiting completed."
    echo "Remove executing files."
    rm $gen_in $gen_out expected.txt
elif [[ $arg = "clear_test" ]]
then
    echo "Clearing test..."
    rm $gen_in $gen_in.cpp $gen_out $gen_out.cpp expected.txt
elif [[ $arg = "debug" ]]
then
    sol="${2:-solution}"
    echo "Build for debugging"
    g++ -std=c++14 -g -o debugger $sol.cpp
elif [[ $arg = "commit" ]]
then
    msg=${3:-test}
    git add input.txt solution.cpp
    git commit -m "$dir_name: $msg"
else
    sol="${2:-solution}"
    g++ -std=c++14 -o solution solution.cpp
    ./$sol < input.txt > output.txt
    cat output.txt
    
    echo "Remove executing file."
    rm $sol
fi
echo "Done."

