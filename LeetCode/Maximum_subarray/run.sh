#! /bin/zsh
echo "Compiling..."
g++ -o sol.o solution.cpp
echo "Done.\nExecuting..."
./sol.o < input.txt
echo "Done."
