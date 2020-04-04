// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem:
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> read_array(string line)
{
    stringstream ss(line);
    int num;
    vector<int> nums;
    while (ss >> num)
    {
        nums.push_back(num);
    }
    return nums;
}

void print_array(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void swap(int& a, int& b) {
    int t = b;
    b = a;
    a = t;
}

void move_zeros(vector<int>& nums) {
    int size = nums.size();
    int nz = 0;
    int i = 0;
    while (nz < size) {
        if (nums[nz] != 0)
            swap(nums[nz], nums[i++]);
        nz++;
    }
}

int main(int argc, char const *argv[])
{
    int n_testcase;
    scanf("%d\n", &n_testcase);
    while (n_testcase--)
    {
        string line;
        getline(cin, line);
        vector<int> nums = read_array(line);
        move_zeros(nums);
        print_array(nums);
    }
    return 0;
}