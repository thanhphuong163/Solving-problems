// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem:
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define vc vector<char>
#define vvc vector<vc>

using namespace std;

// Read input
void read_array(string line, vector<char> &nums)
{
    stringstream ss(line);
    char c;
    while (ss >> c)
    {
        nums.push_back(c);
    }
}

// Print out input
void print_array(vector<char> &nums)
{
    for (char i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
Write your solution here
*/
int numIslands(vvc &grid)
{

    return 0;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int rows, cols;
    while (cin >> rows >> cols)
    {
        cin.ignore();
        string line;
        vvc grid(rows);
        while (rows--)
        {
            getline(cin, line);
            vc row;
            read_array(line, row);
            grid.push_back(row);
            print_array(row);
        }
        cout << endl;
        // cout << numIslands(grid) << endl;
    }
#endif
    return 0;
}
