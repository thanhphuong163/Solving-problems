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

void reverse(vector<int> &nums, int l, int r)
{
    while (l < r)
    {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}

// Find the closest value which is greater than key.
int bsearch(vector<int> &nums, int l, int r, int key)
{
    int indx = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= key)
            r = mid - 1;
        else
        {
            l = mid + 1;
            if (indx == -1 || nums[indx] >= nums[mid])
                indx = mid;
        }
    }
    return indx;
}

void next_permutation(vector<int> &nums)
{
    int size = nums.size();
    int i = size - 2;
    while (i >= 0 && nums[i + 1] <= nums[i])
        i--;
    if (i >= 0)
    {
        int indx = bsearch(nums, i + 1, size - 1, nums[i]);
        swap(nums[i], nums[indx]);
        reverse(nums, i + 1, size - 1);
        // cout << i << indx << endl;
    }
    else
    {
        reverse(nums, 0, size - 1);
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
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != nums.size() - 1)
                cout << nums[i] << " ";
            else
                cout << nums[i];
        }
        puts("");
    }
    return 0;
}
