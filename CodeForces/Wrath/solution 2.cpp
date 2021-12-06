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
Using an extra array
    0 1 2 3 4 5 6 7 8 9
    1 1 3 0 0 0 2 1 0 3
     -1-1 3 4 4 4 6 6 6
*/

int kill(vector<int> &nums)
{
    int n = nums.size();
    int size = nums.size();
    vector<int> a(size);
    int minDead = INT_MAX;
    for (int i = size-1; i >= 1; i--) {
        if (i - nums[i] < minDead) {
            a[i] = i - nums[i];
            minDead = i - nums[i];
        }
        else {
            a[i] = minDead;
        }
    }
    for (int i = 0; i < size-1; i++) {
        if (i >= a[i+1]) {
            n--;
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
