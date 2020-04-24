// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/greedy-florist/problem
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#define ulli unsigned long long int

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
    n k
    a = floor(n/k) + 1
    r = n mod k
    n = 7
    k = 3
    1 3 5 7 9 11 13
    3 2 2 2 1  1  1
    for i = 0 .. r:
        sum += cost[i]*a
    for i = r .. n-1:
        if (i - r) % k == 0:
            --a;
        sum += cost[i]*a;
*/
ulli buyFlower(vector<ulli> cost, ulli k)
{
    ulli n = cost.size();
    ulli a = floor(n / k) + 1;
    ulli r = n % k;
    ulli sum = 0;
    for (ulli i = 0; i < r; ++i)
    {
        sum += cost[i] * a;
    }
    for (ulli i = r; i < n; ++i)
    {
        if ((i - r) % k == 0)
            --a;
        sum += cost[i] * a;
    }
    return sum;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    ulli n, k;
    while (cin >> n >> k)
    {
        cin.ignore();
        getline(cin, line);
        vector<ulli> nums;
        read_array(line, nums);
        cout << buyFlower(nums, k) << endl;
    }
#endif
    return 0;
}
