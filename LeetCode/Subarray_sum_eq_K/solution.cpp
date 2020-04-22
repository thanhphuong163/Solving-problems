// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/subarray-sum-equals-k/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

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
    Use prefix sum hash technique
    prefixSum[j] - k = prefixSum[i] 
*/
int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> hash;
    int count = 0, prefixSum = 0;
    hash[0] = 1;
    for (auto n : nums)
    {
        prefixSum += n;
        count += hash[prefixSum - k];
        hash[prefixSum]++;
    }
    return count;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    while (getline(cin, line))
    {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> nums;
        read_array(line, nums);
        cout << subarraySum(nums, k) << endl;
    }
#endif
    return 0;
}
