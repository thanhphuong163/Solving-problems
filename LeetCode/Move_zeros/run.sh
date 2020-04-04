#! /bin/zsh

echo "Compiling..."
g++ -o gen_input.o gen_input.cpp
g++ -o gen_output.o gen_output.cpp
g++ -o sol.o solution.cpp
echo "Done.nExecuting...n"
./gen_input.o > input.txt
./gen_output.o < input.txt > expected.txt
