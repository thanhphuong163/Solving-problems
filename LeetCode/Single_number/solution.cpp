// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/single-number/
// Submit:

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int a = 0;
    for (const int i : nums)
    {
        a ^= i;
    }
    return a;
}

int main(int argc, char const *argv[]) {
    int n_testcase;
    scanf("%d\n", &n_testcase);
    while (n_testcase > 0) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int i;
        vector<int> nums;
        while (ss >> i) {
            nums.push_back(i);
        }
        cout << singleNumber(nums) << endl;
        n_testcase--;
    }
    return 0;
}
