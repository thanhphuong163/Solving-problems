// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/set-matrix-zeroes/
// Submit:

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void print_matrix(vector< vector<int> >& matrix) {
    const int H = matrix.size();
    const int W = matrix[0].size();
    for (int row = 0; row < H; ++row)
    {
        for (int col = 0; col < W; ++col)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void set_zeros_1(vector< vector<int> >& matrix) {
    // This is a solution with space complexity O(H+W),
    // Where H and W are sizes of the matrix
    const int H = matrix.size();
    const int W = matrix[0].size();
    vector<bool> row_zero(H);
    vector<bool> column_zero(W);
    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
            if (matrix[row][col] == 0) {
                row_zero[row] = true;
                column_zero[col] = true;
            }
        }
    }
    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
            if (row_zero[row] || column_zero[col]) {
                matrix[row][col] = 0;
            }
        }
    }
    print_matrix(matrix);
}

void set_zeros_2(vector< vector<int> >& matrix) {
    // This is a solution with space complexity O(W),
    // Where H and W are sizes of the matrix
    const int H = matrix.size();
    const int W = matrix[0].size();
    vector<bool> row_zero(H);
    
    for (int row = 0; row < H; ++row)
    {
        for (int col = 0; col < W; ++col)
        {
            if (matrix[row][col] == 0)
            {
                row_zero[row] = true;
            }
        }
    }
    for (int row = 0; row < H; ++row)
    {
        bool contains_zeros = false;
        for (int col = 0; col < W; ++col) {
            if (matrix[row][col] == 0) contains_zeros = true;
            break;
        }
        for (int col = 0; col < W; ++col)
        {
            if (row_zero[row] || contains_zeros)
            {
                matrix[row][col] = 0;
            }
        }
    }
    print_matrix(matrix);
}

int main(int argc, char const *argv[]) {
    int n_testcase;
    scanf("%d\n", &n_testcase);
    while (n_testcase > 0) {
        int H, W;
        cin >> H >> W;
        vector< vector<int> > matrix(H, vector<int>(W));
        for (int row = 0; row < H; ++row) {
            for (int col = 0; col < W; ++col) {
                cin >> matrix[row][col];
            }
        }
        print_matrix(matrix);
        cout << endl;
        set_zeros_2(matrix);
        n_testcase--;
    }
    return 0;
}
