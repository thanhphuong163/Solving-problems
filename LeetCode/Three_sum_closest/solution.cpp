// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/3sum-closest/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

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

int three_sum_closest(vector<int> &nums, int target)
{
    int size = nums.size();
    int sum, min_diff = 10 ^ 6;
    // sort the array
    sort(nums.begin(), nums.end());
    // Two pointers technique gives the O(n^2) solution
    for (int i = 0; i < size; i++)
    {
        while (nums[i] == nums[i + 1])
            i++; // skip repeating number
        int t_target = target - nums[i];
        int l = i + 1;
        int r = size - 1;
        do
        {
            int t_sum = nums[l] + nums[r];
            if (abs(t_sum - t_target) < min_diff)
            {
                sum = nums[i] + t_sum;
                min_diff = abs(t_sum - t_target);
            }
            while (nums[l] == nums[l + 1])
                l++; // skip repeating numbers
            while (nums[r] == nums[r - 1])
                r--; // skip repeating numbers
            if (t_sum <= t_target) l++;
            else r--;
        } while (l < r);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int target;
    while (cin >> target)
    {
        cin.ignore();
        string line;
        getline(cin, line);
        vector<int> nums;
        read_array(line, nums);
        cout << three_sum_closest(nums, target) << endl;
    }
    return 0;
}

// 1
// -1 2 1 -4
