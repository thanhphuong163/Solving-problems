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
#include <map>

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
    Use DP
    Complexity: O(n*n*m)
*/
void executeTask(vvulli ss, vvi tasks) {
    int n = ss.size();
    int m = ss[0].size();
    int k = tasks.size();
    
    vector<int> memRow(n);
    vector<int> memCol(m);
    for(int i = 1; i < n; i++) {
        int maxx = 0;
        for(int j = 0; j < m; j++) {
            if (memCol[j] < i) {
                for (int k = i; k < n; k++)
                {
                    if (ss[k - 1][j] <= ss[k][j])
                    {
                        memCol[j] = k;
                        break;
                    }
                }
            }
            maxx = max(maxx, memCol[j]);
        }
        memRow[i-1] = maxx;
    }
    memRow[n-1] = n-1;
    // for (int t = 0; t < k; t++) {
    //     int l = tasks[t][0] - 1;
    //     int r = tasks[t][1] - 1;
    //     if (memRow[l] >= r) cout << "Yes" << endl;
    //     else cout << "No" << endl;
    // }
    for (auto i : memRow) {
        cout << i << endl;
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
