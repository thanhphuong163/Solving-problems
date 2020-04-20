// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1006/C
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Read input
void read_array(string line, vector<int> &nums) {
    stringstream ss(line);
    int num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}

// Print out input
void print_array(vector<int> &nums) {
    for (int i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    Use two-pointer to determine
    left = 0
    right = n-1
    while (left < right)
        if sum1 < sum3 then left++
        if sum1 > sum3 then right--
        if sum1 == sum3 then record the sum
*/
int getPartition(vector<int> &nums) {
    int len = nums.size();
    int left = 0;
    int right = len-1;
    int sum1 = nums[0];
    int sum3 = nums[len-1];
    int res = 0;
    while (left < right) {
        if (sum1 < sum3) left++;
        if (sum1 > sum3) right--;
        if (sum1 == sum3) res = sum1;
    }
    return res;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    int n;
    while (cin >> n)
    {
        cin.ignore();
        getline(cin, line);
        vector<int> nums;
        read_array(line, nums);
        /* your code here */
    }
#endif
    return 0;
}
