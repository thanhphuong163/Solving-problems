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
void isSatisfied(int n, int m, vector<ulli> &t, vector<ulli> &l, vector<ulli> &h)
{
    cout << n << m << endl;
    for (int i = 0; i < n; i++) {
        cout << t[i] << l[i] << h[i] << endl;
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
        vector<ulli> t(n);
        vector<ulli> l(n);
        vector<ulli> h(n);
        for (int i = 0; i < n; i++) {
            cin >> t[i] >> l[i] >> h[i];
            cin.ignore();
        }
        isSatisfied(n,m,t,l,h);
    }
#endif
    return 0;
}
