// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/777/C
// Submit: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#define ulli unsigned long long int
#define vulli vector<ulli>
#define vvulli vector<vulli>

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums) {
    stringstream ss(line);
    ulli num;
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
Write your solution here
*/
void executeTask(int l, int r, vvulli spreadsheet) {
    for (int i = l; i <= r; i++) {
        for (int j = 0; j < spreadsheet[i].size(); j++) {
            cout << spreadsheet[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int n,m,k;
    cin >> n >> m;
    cin.ignore();
    vvulli spreadsheet;
    string line;
    while(n--) {
        vulli nums;
        getline(cin, line);
        read_array(line, nums);
        spreadsheet.push_back(nums);
    }
    cin >> k;
    cin.ignore();
    while(k--) {
        int l,r;
        cin >> l >> r;
        cin.ignore();
        executeTask(l,r,spreadsheet);
    }
#endif
    return 0;
}
