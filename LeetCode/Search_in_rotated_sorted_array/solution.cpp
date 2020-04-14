// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
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

int bin_search(vector<int> &nums, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

/*
    Using binary search can get time complexity O(logN).
    Find the pivot and search in one of the two parts
*/
int get_index(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;
    if (nums.size() == 1)
    {
        return nums[0] == target ? 0 : -1;
    }
    int p = 0;
    int size = nums.size();
    for (int i = 0; i < size - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            p = i + 1;
            break;
        }
    }
    if (p == 0)
        return bin_search(nums, 0, size - 1, target);

    if (nums[0] <= target && target <= nums[p - 1])
        return bin_search(nums, 0, p - 1, target);
    else if (nums[p] <= target && target <= nums[size - 1])
        return bin_search(nums, p, size - 1, target);
    else
        return -1;
}

// #define DEBUG_MODE

int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    int target = 19;
    vector<int> nums = {7, 8, 9, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 0, 1, 3, 4, 5};
    cout << get_index(nums, target) << endl;
#else // test mode
    int target;
    while (cin >> target)
    {
        cin.ignore();
        string line;
        getline(cin, line);
        vector<int> nums;
        read_array(line, nums);
        cout << get_index(nums, target) << endl;
    }
#endif
    return 0;
}
