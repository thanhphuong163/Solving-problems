// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/smallest-range-ii/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define ulli unsigned long long int

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums)
{
    stringstream ss(line);
    ulli num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

// Print out input
void print_array(vector<ulli> &nums)
{
    for (ulli i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
Write your solution here
*/
ulli smallestRangeII(vector<ulli> &A, ulli K)
{
    int size = A.size();
    ulli min = A[0], max = A[0];
    for (int i = 1; i < size; i++)
    {
        if (A[i] < min)
            min = A[i];
        if (A[i] > max)
            max = A[i];
    }
    return max - min;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    while (getline(cin, line))
    {
        vector<ulli> nums;
        read_array(line, nums);
        ulli k;
        cin >> k;
        cout << smallestRangeII(nums, k) << endl;
    }
#endif
    return 0;
}
