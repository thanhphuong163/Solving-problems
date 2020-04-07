// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem:
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

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

int count_elements(vector<int> &nums)
{
    int count = 0;
    set<int> si;
    for (int i = 0; i < nums.size(); i++)
    {
        si.insert(nums[i]);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (si.find(nums[i] + 1) != si.end())
            count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums;
        read_array(line, nums);
        cout << count_elements(nums) << endl;
    }
    return 0;
}
