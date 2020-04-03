// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/maximum-subarray/
// Submit:

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define max(a,b) (a > b ? a : b)

using namespace std;

void print_test_case(int i, int my_ans, int ans) {
    string status = my_ans == ans ? "Success" : "Fail";
    printf("Test case #%d (output: %d, expected: %d): %s", i, my_ans, ans, status.c_str());
}

int cal_sum(vector<int>& nums, int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; ++k) {
        sum += nums[k];
    }
    return sum;
}

// Brute force to get the correct answers
int max_subarray(vector<int>& nums) {
    int max_sum;
    if (!nums.empty()) {
        max_sum = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i; j < nums.size(); ++j)
            {
                max_sum = max(cal_sum(nums, i, j), max_sum);
            }
        }
    }
    else
        max_sum = 0;
    return max_sum;
}

int main(int argc, char const *argv[]) {
    int n_testcase;
    scanf("%d\n", &n_testcase);
    int i = 1;
    while (i++ <= n_testcase) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << max_subarray(nums) << endl;
    }

    return 0;
}
