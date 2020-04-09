// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/3sum-closest/
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

int three_sum_closest(vector<int> &nums, int target)
{
}

int main(int argc, char const *argv[])
{
    int target;
    while (cin >> target)
    {
        cin.ignore();
        string line;
        vector<int> nums;
        read_array(line, nums);
        cout << three_sum_closest(nums, target) << endl;
    }
    return 0;
}

// 1
// -1 2 1 -4
