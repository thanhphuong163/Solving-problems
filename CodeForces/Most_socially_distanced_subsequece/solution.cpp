// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1364/B

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define ulli unsigned long long int
#define vulli vector<ulli>

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums)
{
    stringstream ss(line);
    ulli num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

// Print out input
void print_array(vector<ulli> &nums)
{
    for (ulli i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
Write your solution here
*/
vector<ulli> findSubsequence(vulli &nums)
{
    int n = nums.size();
    vulli ans;
    bool isUp = nums[0] < nums[1];
    ans.push_back(nums[0]);
    ans.push_back(nums[1]);
    int p = 1;
    for (int i = 2; i < n; ++i)
    {
        if ((nums[i] > ans[p]) == isUp)
            ans[p] = nums[i];
        else
        {
            ans.push_back(nums[i]);
            p++;
            isUp = !isUp;
        }
    }
    cout << ans.size() << endl;
    return ans;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int t, n;
    cin >> t;
    string line;
    while (t--)
    {
        cin >> n;
        cin.ignore();
        getline(cin, line);
        vector<ulli> nums;
        read_array(line, nums);
        vulli ans = findSubsequence(nums);
        print_array(ans);
    }
#endif
    return 0;
}
