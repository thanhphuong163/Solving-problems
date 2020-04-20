// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Read input
void read_array(string line, vector<int> &nums)
{
    stringstream ss(line);
    int num;
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

// Binary search
int bsearch(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

/*
    Use binary search to find the index of target
    Use two pointers to expand the range then.
*/
vector<int> searchRange(vector<int> &nums, int target)
{
    int index = bsearch(nums, target);
    if (index == -1)
    {
        return {-1, -1};
    }
    else
    {
        int left = index;
        int right = index;
        while (left > 0 && nums[left - 1] == target)
            left--;
        while (right < nums.size() - 1 && nums[right + 1] == target)
            right++;
        return {left, right};
    }
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
        vector<int> nums;
        read_array(line, nums);
        int target;
        cin >> target;
        cin.ignore();
        vector<int> res = searchRange(nums, target);
        print_array(res);
    }
#endif
    return 0;
}
