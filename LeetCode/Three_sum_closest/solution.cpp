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
    int sum = nums[0] + nums[1] + nums[2];
    // sort the array
    sort(nums.begin(), nums.end());
    // Two pointers technique gives the O(n^2) solution
    for (int i = 0; i < size - 2; i++)
    {
        int l = i + 1;
        int r = size - 1;
        while (l < r)
        {
            int t_sum = nums[i] + nums[l] + nums[r];
            if (abs(t_sum - target) < abs(sum - target))
                sum = t_sum;
            
            if (t_sum < target)
                l++;
            else if (t_sum > target) 
                r--;
            else
                return target;
        }
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
