// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1006/C
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
void print_array(vector<int> &nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    Use two-pointer to determine
    left = 0
    right = n-1
    while (left < right)
        if sum1 < sum3 then left++
        if sum1 > sum3 then right--
        if sum1 == sum3 then record the sum
    NOTE: Be aware with very large integer, better use unsigned long long int
*/
ulli getPartition(vector<ulli> &nums)
{
    long long len = nums.size();
    long long left = 0;
    long long right = len - 1;
    ulli sum1 = nums[left];
    ulli sum3 = nums[right];
    ulli res = 0;
    while (left < right)
    {
        if (sum1 == sum3)
        {
            res = sum1;
            sum1 += nums[++left];
            sum3 += nums[--right];
        }
        else if (sum1 > sum3)
        {
            sum3 += nums[--right];
        }
        else
        {
            sum1 += nums[++left];
        }
    }
    return res;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    long long n;
    while (cin >> n)
    {
        cin.ignore();
        getline(cin, line);
        vector<ulli> nums;
        read_array(line, nums);
        cout << getPartition(nums) << endl;
    }
#endif
    return 0;
}
