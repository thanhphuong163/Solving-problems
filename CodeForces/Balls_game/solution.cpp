// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/430/B

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define ulli unsigned long long int
#define vulli vector<ulli>
#define vi vector<int>
#define max(a, b) a > b ? a : b

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
void print_array(vector<ulli> &nums)
{
    for (ulli i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    Use two-pointer technique
    Iterate over the balls
    when balls[i] == x then use left and right pointer to expand
    max length = right - left + 1
*/
int play(vi &balls, int x)
{
    int n = balls.size();
    int max_len = 0;
    int i = 0;
    while (i < n)
    {
        if (balls[i] == x)
        {
            int l = i;
            int r = i;
            while (balls[r + 1] == x)
                r++;
            i = r;
            int tmp = r - l + 1;
            if (tmp >= 2)
            {
                while (balls[l - 1] == balls[r + 1])
                {
                    tmp = r-l+1;
                    l--;
                    r++;
                    while (balls[r + 1] == balls[r])
                        r++;
                    while (balls[l - 1] == balls[l])
                        l--;
                    tmp = (r - l + 1) - tmp;
                    if (tmp <= 2) {
                        l++;
                        r--;
                        break;
                    }
                }
                max_len = max(max_len, r - l + 1);
            }
        }
        i++;
    }
    return max_len;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int n, k, x;
    string line;
    while (cin >> n >> k >> x)
    {
        cin.ignore();
        getline(cin, line);
        vector<int> nums;
        read_array(line, nums);
        cout << play(nums, x) << endl;
    }
#endif
    return 0;
}
