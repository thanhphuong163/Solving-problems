// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
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

// Binary search
bool bsearch(vector<int> &nums, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return true;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

/*
    - Find rotating point.
    - Use binary search on the part which might contains the seeked value.
*/
bool search(vector<int> &nums, int target) {
    if (nums.size() == 0) return false;
    if (nums.size() == 1) return nums[0] == target;
    int n = nums.size();
    int p = 0;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i+1])
            p = i+1;
    }
    if (p == 0)
        return bsearch(nums, 0, n-1, target);
    else if (nums[0] <= target && target <= nums[p-1])
        return bsearch(nums, 0, p-1, target);
    else if (nums[p] <= target && target <= nums[n - 1])
        return bsearch(nums, p, n-1, target);
    else
        return false;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    while (getline(cin, line))
    {
        vector<int> nums;
        read_array(line, nums);
        int target;
        cin >> target;
        cin.ignore();
        if (search(nums, target))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
#endif
    return 0;
}
