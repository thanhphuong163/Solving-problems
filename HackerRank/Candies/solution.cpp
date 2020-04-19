// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/candies/problem
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
    Use DP to store the number of candies for each student
    Traverse forward and backward to give candies in terms of the rules.
*/
long candies(int n, vector<int> arr)
{
    if (n == 1)
        return 1;
    vector<long> dp(n, 1);
    // Forward
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            dp[i] += dp[i - 1];
    }
    // Backward
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] && dp[i] < dp[i + 1] + 1)
            dp[i] = dp[i + 1] + 1;
    }
    long numCandies = 0;
    for (long candy : dp)
    {
        numCandies += candy;
    }
    return numCandies;
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            int arr_item;
            cin >> arr_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            arr[i] = arr_item;
        }

        long result = candies(n, arr);

        cout << result << "\n";
    }

    return 0;
}
