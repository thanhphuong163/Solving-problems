// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/253/B
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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
    - sort
    3 4 4 5 7 8
    - use two-pointer technique
    if (nums[0]*2 >= nums[n-1]) return 0;
    l = 0;
    r = 0;

*/
int eraseResult(vector<ulli> &nums)
{
    ulli n = nums.size();
    sort(nums.begin(), nums.end());
    if (nums[0] * 2 >= nums[n - 1])
        return 0;
    ulli l = 0;
    ulli r = 0;
    ulli ans = n;
    while (r < n)
    {
        if (nums[l] * 2 >= nums[r])
        {
            r++;
        }
        else
        {
            l++;
        }
        ans = min(ans, n - r + l + 1);
    }
    return ans;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string line;
    long long n;
    while (cin >> n)
    {
        cin.ignore();
        getline(cin, line);
        vector<ulli> nums;
        read_array(line, nums);
        cout << eraseResult(nums) << endl;
    }
#endif
    return 0;
}
