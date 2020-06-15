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
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums) {
    stringstream ss(line);
    ulli num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}

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
void print_array(vector<ulli> &nums) {
    for (ulli i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    Use DP: create a same-size grid
    if (spreadsheet[i][j] >= spreadsheet[i-1][j]) {
        incr[i][j] = incr[i-1][j] + 1;
    }
    else {
        incr[i][j] = 1;
    }
*/
void executeTask(vvulli spreadsheet, vvi tasks) {
    int n = spreadsheet.size();
    int m = spreadsheet[0].size();
    int k = tasks.size();
    int incr[n][m];
    // memset(incr, 0, sizeof(incr));
    for (int j = 0; j < m; j++) {
        incr[0][j] = 1;
    }
    for(int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (spreadsheet[i][j] >= spreadsheet[i-1][j]) {
                incr[i][j] = incr[i-1][j] + 1;
            }
            else {
                incr[i][j] = 1;
            }
        }
    }
    for (int t = 0; t < k; t++) {
        int l = tasks[t][0];
        int r = tasks[t][1];
        int tot = r - l;
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (incr[r-1][j] - incr[l-1][j] == tot) {
                ok = true;
                break;
            }
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
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
    vvi tasks;
    while(k--) {
        vi pair;
        getline(cin, line);
        read_array(line, pair);
        tasks.push_back(pair);
    }
    executeTask(spreadsheet, tasks);
#endif
    return 0;
}
