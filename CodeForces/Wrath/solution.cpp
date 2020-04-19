// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/892/B
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Read input
void read_array(string line, vector<int> &nums)
{
    stringstream ss(line);
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

// Print out input
void print_array(vector<int> &nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
Write your solution here
*/
int kill(vector<int> &nums)
{
    int n = nums.size();
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (i >= j - nums[j]) {
                n--;
                break;
            }
        }
    }
    return n;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    vector<int> nums{1, 1, 3, 0, 0, 0, 2, 1, 0, 3};
    cout << kill(nums) << endl;
#else
    int n;
    while (cin >> n)
    {
        cin.ignore();
        string line;
        getline(cin, line);
        vector<int> nums;
        read_array(line, nums);
        cout << kill(nums) << endl;
    }
#endif
    return 0;
}
