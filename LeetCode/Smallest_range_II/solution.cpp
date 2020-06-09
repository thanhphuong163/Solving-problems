// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/smallest-range-ii/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

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
    sort(A.begin(), A.end());
    int ans = A[size-1] - A[0];
    for (int i = 0; i < size - 1; i++) {
        int a = A[i], b = A[i+1];
        int high = max(A[size-1]-K, a+K);
        int low = min(A[0]+K, b-K);
        ans = min(ans, high - low);
    }
    return ans;
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
        cin.ignore();
        cout << smallestRangeII(nums, k) << endl;
    }
#endif
    return 0;
}
