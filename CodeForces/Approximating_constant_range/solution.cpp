// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/602/B
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#define ulli unsigned long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

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
    11
    0 1 2 3 4 5 6 7 8 9 10
    5 4 5 5 6 7 8 8 8 7 6
    -1 1 0 1 1 1 0 0 -1 -1
    1 2 3 3  2
     1 1 0 -1
*/
int getRange(vector<ulli> &nums)
{
    long n = nums.size();
    if (n <= 2) return n;
    long maxRange = 2;
    long l = 0;
    long lastDiff = 0;
    long j = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] - nums[i-1] == 0) {
            maxRange = max(maxRange, i-l+1);
        }
        else {
            if (nums[i] - nums[i-1] != lastDiff) {
                maxRange = max(maxRange, i - l + 1);
                lastDiff = nums[i] - nums[i - 1];
            }
            else {
                l = j;
            }
            j = i;
        }
    }
    return maxRange;
}

// #define DEBUG_MODE

int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    vector<ulli> nums = {5, 4, 5, 5, 6, 7, 8, 8, 8, 7, 6};
    cout << getRange(nums) << endl;
#else
    string line;
    int n;
    while (cin >> n)
    {
        cin.ignore();
        getline(cin, line);
        vector<ulli> nums;
        read_array(line, nums);
        cout << getRange(nums) << endl;
    }
#endif
    return 0;
}
