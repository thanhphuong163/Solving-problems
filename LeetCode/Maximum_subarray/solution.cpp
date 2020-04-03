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
    printf("Test case #%d (output: %d, expected: %d): %s\n", i, my_ans, ans, status.c_str());
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
    else if (nums.size() == 1)
        max_sum = nums[0];
    else
        max_sum = 0;
    return max_sum;
}

// DP method to get time complexity O(n)
int maxSubarray_DP(vector<int>& nums) {
    int max_sum = nums[0];
    int curr_sum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (curr_sum < 0) curr_sum = 0;
        curr_sum += nums[i];
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

// Using Divide and Conquer (DnC)
int maxInThree(int a, int b, int c) {
    return max(max(a,b),c);
}

int max_subarray_sum(int left, int right, vector<int>& nums) {
    if (left == right) return nums[left];
    int mid = (left + right) / 2;
    int leftBounder = 0, rightBounder = 0;

    int leftMax = max_subarray_sum(left, mid, nums);
    int rightMax = max_subarray_sum(mid + 1, right, nums);

    int leftBounderMax = nums[mid];
    for (int i = mid; i >= left; i--) {
        leftBounder += nums[i];
        leftBounderMax = max(leftBounderMax, leftBounder);
    }

    int rightBounderMax = nums[mid+1];
    for (int i = mid + 1; i <= right; i++) {
        rightBounder += nums[i];
        rightBounderMax = max(rightBounderMax, rightBounder);
    }

    return maxInThree(leftMax, rightMax, leftBounderMax + rightBounderMax);
}

int maxSubarray_DnC(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    return max_subarray_sum(0, nums.size() - 1, nums);
}

int main(int argc, char const *argv[]) {
    int n_testcase;
    scanf("%d\n", &n_testcase);
    int i = 0;
    while (i++ <= n_testcase) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        // int my_ans = maxSubarray_DP(nums);
        int my_ans = maxSubarray_DnC(nums);
        int ans = max_subarray(nums);
        print_test_case(i, my_ans, ans);
    }

    return 0;
}
