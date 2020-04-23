// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 
// Submit: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define ulli unsigned long long int

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums) {
    stringstream ss(line);
    ulli num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}

// Print out input
void print_array(vector<ulli> &nums) {
    for (ulli i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    sort array
    2 2 3 4
    2 3 3 3 4 5 6 6 7 8
    mid = (n-1) / 2
    l = mid
    r = mid
    while (nums[l]*2 >= nums[r]) {
        if (l > 0 && nums[l-1]*2 >= nums[r])
            l--;
        if (r < n-1 && nums[l]*2 >= nums[r+1])
            r++;
        if (l == 0 && r == n-1)
            len = n;
            break;
        if (nums[l-1]*2 < nums[r] && nums[l]*2 < nums[r+1])
            len = r-l+1;
            break;
    }
    return n - len;
*/
int eraseResult(vector<ulli> &nums) {
    int n = nums.size();
    int mid = (n-1)/2;
    int l = mid;
    int r = mid;
    int len = 1;
    while (nums[l] * 2 >= nums[r]) {
        if (l > 0 && nums[l - 1] * 2 >= nums[r])
            l--;
        if (r < n - 1 && nums[l] * 2 >= nums[r + 1])
            r++;
        if (l == 0 && r == n - 1) {
            len = n;
            break;
        }
        if (nums[l - 1] * 2 < nums[r] && nums[l] * 2 < nums[r + 1]) {
            len = r - l + 1;
            break;
        }
    }
    return n - len;
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
        vector<ulli> nums;
        read_array(line, nums);
        cout << eraseResult(nums) << endl;
    }
#endif
    return 0;
}
