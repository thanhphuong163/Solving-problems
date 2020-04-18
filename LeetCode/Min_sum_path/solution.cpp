// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/minimum-path-sum/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

// Read input
void read_array(string line, vector<int> &nums) {
    stringstream ss(line);
    int num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}

/*
    Use iterative DP
    DP[0][0] = grid[0][0]
    DP[i][j] = grid[i][j] + min{DP[i-1][j], DP[i][j-1]}
*/
int minPathSum(vvi &grid) {
    int rows = grid.size();
    if (rows == 0) return 0;
    int cols = grid[0].size();
    if (cols == 0) return 0;
    vvi dp;
    for (int i = 0; i < rows; i++) {
        vi row(cols, INT_MAX);
        dp.push_back(row);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i==0 && j==0)
                dp[i][j] = grid[0][0];
            else {
                int above = i > 0 ? dp[i-1][j] : INT_MAX;
                int left = j > 0 ? dp[i][j-1] : INT_MAX;
                dp[i][j] = grid[i][j] + min(above, left);
            }
        }
    }
    return dp[rows-1][cols-1];
}

// In place DP
int minPathSumDPInPlace(vvi &grid) {
    int rows = grid.size();
    if (rows == 0)
        return 0;
    int cols = grid[0].size();
    if (cols == 0)
        return 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != 0 || j != 0)
            {
                int above = i > 0 ? grid[i - 1][j] : INT_MAX;
                int left = j > 0 ? grid[i][j - 1] : INT_MAX;
                grid[i][j] = grid[i][j] + min(above, left);
            }
        }
    }
    return grid[rows-1][cols-1];
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int rows, cols;
    while (cin >> rows >> cols)
    {
        cin.ignore();
        string line;
        vvi grid;
        while (rows--) {
            getline(cin, line);
            vi row;
            read_array(line, row);
            grid.push_back(row);
        }
        
        cout << minPathSumDPInPlace(grid) << endl;
    }
#endif
    return 0;
}
