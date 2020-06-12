// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1304/C
// Submit: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#define ulli unsigned long long int
#define lli long long int

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
    Using greedy algorithm with two pointers in order to create a feasible range
*/
void isSatisfied(int n, int m, vector<lli> &t, vector<lli> &l, vector<lli> &h)
{
    bool ans = true;
    lli mn = m;
    lli mx = m;
    int prev = 0;
    for (int i = 0; i < n; i++) {
        lli k = t[i] - prev;
        mn -= k;
        mx += k;
        if (l[i] > mx || h[i] < mn) {
            ans = false;
            break;
        }
        mn = max(mn, l[i]);
        mx = min(mx, h[i]);
        prev = t[i];
    }

    if (ans) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int t;
    cin >> t;
    cin.ignore();
    while (t--){
        int n, m;
        cin >> n >> m;
        cin.ignore();
        vector<lli> t(n);
        vector<lli> l(n);
        vector<lli> h(n);
        for (int i = 0; i < n; i++) {
            cin >> t[i] >> l[i] >> h[i];
            cin.ignore();
        }
        isSatisfied(n,m,t,l,h);
    }
#endif
    return 0;
}
