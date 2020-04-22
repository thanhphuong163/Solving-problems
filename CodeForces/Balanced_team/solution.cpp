// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1133/C
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define ulli unsigned long long int
#define max(a, b) (a > b ? a : b)

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
    Sort array
    Use two-pointer to determine
    nums[end] - nums[start] <= 5
    number of students = end - start + 1
    1 10 17 12 15 2
    1 2 10 12 15 17

*/
long assembleTeam(vector<ulli> &nums)
{
    long size = nums.size();
    long start = 0;
    long end = 0;
    long maxSize = 0;
    sort(nums.begin(), nums.end());
    while (start < size)
    {
        if (nums[end] - nums[start] <= 5)
        {
            maxSize = max(maxSize, end - start + 1);
            if (end < size - 1)
                end++;
            else
                start++;
        }
        else
        {
            start++;
        }
    }
    return maxSize;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    int n;
    while (cin >> n)
    {
        cin.ignore();
        getline(cin, line);
        vector<ulli> nums;
        read_array(line, nums);
        cout << assembleTeam(nums) << endl;
    }
#endif
    return 0;
}
