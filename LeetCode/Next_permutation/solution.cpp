// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/next-permutation/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_array(string line, vector<int> &nums)
{
    stringstream ss(line);
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void next_permutation(vector<int> &nums)
{
    int i = nums.size() - 1;
    while (i > 0)
    {
        if (nums[i - 1] < nums[i])
        {
            swap(nums[i - 1], nums[i]);
            break;
        }
        i--;
    }
    if (i == 0)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
}

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums;
        read_array(line, nums);
        next_permutation(nums);
        for (int i : nums)
        {
            cout << i << " ";
        }
        puts("");
    }
    return 0;
}

// 1 2 3 4
// 1 2 4 3
// 1 3 2 4
// 1 3 4 2
// 1 4 2 3

// 4 3 2 1
// 1 2 3 4
