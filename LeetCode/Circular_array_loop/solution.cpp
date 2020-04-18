// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/circular-array-loop/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

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
    - Modulo all values in order to get values which are smaller than size
    - Go through all elements:
        - assign element at start point
        - formula: step = (step + size + nums[step]) % size
        - use (element + 1) * n to mark visited elements
*/
bool circularArrayLoop(vector<int> &nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        nums[i] %= size;
    }
    for (int i = 0; i < size; i++) {
        int step = i;
        int lastStep = 0;
        bool isForward = nums[i] > 0;
        while (nums[step]%size != 0 && (nums[step] > 0) == isForward) {
            lastStep = step;
            step = (step + size + nums[step]) % size;
            nums[lastStep] = (i+1) * size;
            if (nums[step] == (i+1)*size)
                return true;
        }
    }
    return false;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    vector<int> nums{3,1,2};
    if (circularArrayLoop(nums))
        cout << "True" << endl;
    else
        cout << "False" << endl;
#else
    string line;
    while (getline(cin, line))
    {
        vector<int> nums;
        read_array(line, nums);
        if (circularArrayLoop(nums))
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
#endif
    return 0;
}
