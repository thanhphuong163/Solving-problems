// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/maximal-square/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#define ulli unsigned long long int
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>

using namespace std;

// Read input
void read_array(string line, vector<char> &nums) {
    stringstream ss(line);
    char num;
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
    if (matrix[i][j] == '1') {
        minCell = min{dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}
        dp[i][j] = sqr(sqrt(min)+1);
    }
    else {
        dp[i][j] = 0;
    }
*/
int maximalSquare(vvc &matrix)
{
    int m = matrix.size();
    if (m == 0)
        return 0;
    int n = matrix[0].size();
    if (n == 0)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxSquare = 0;
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == '1')
        {
            dp[i][0] = 1;
            maxSquare = 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (matrix[0][i] == '1')
        {
            dp[0][i] = 1;
            maxSquare = 1;
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == '1') {
                int minCell = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                dp[i][j] = (int)pow((sqrt(minCell) + 1), 2);
                maxSquare = max(maxSquare, dp[i][j]);
            }
        }
    }
    return maxSquare;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int m, n;
    string line;
    while (cin >> m >> n)
    {
        cin.ignore();
        vvc matrix;
        while (m--) {
            getline(cin, line);
            vector<char> row;
            read_array(line, row);
            matrix.push_back(row);
        }
        cout << maximalSquare(matrix) << endl;
    }
#endif
    return 0;
}
