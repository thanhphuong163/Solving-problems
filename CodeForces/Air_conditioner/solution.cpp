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
    Using greedy algorithm:
*/
void isSatisfied(int n, int m, vector<lli> &t, vector<lli> &l, vector<lli> &h)
{
    bool ans = true;
    for (int i = 1; i <= n; i++) {
        if (h[i] < l[i-1])  // cooling
        {
            if ((t[i] - t[i-1]) < (l[i-1] - h[i])) ans = false;
        }
        else if (l[i] > h[i-1]) // heating
        {
            if ((t[i] - t[i-1]) < (l[i] - h[i-1])) ans = false;
        }
    }
    if (ans) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
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
        vector<lli> t(n+1);
        vector<lli> l(n+1);
        vector<lli> h(n+1);
        t[0] = 0;
        l[0] = m;
        h[0] = m;
        for (int i = 1; i <= n; i++) {
            cin >> t[i] >> l[i] >> h[i];
            cin.ignore();
        }
        isSatisfied(n,m,t,l,h);
    }
#endif
    return 0;
}
