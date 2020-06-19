// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/733/C
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define ulli unsigned long long int
#define vulli vector<ulli>
#define plc pair<ulli, char>
#define vplc vector<plc>

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
    for each b[j]: check if there is a consecutive subarray whose sum is equal to b[j]
    if all b[j] satisfy then print yes, else print no
    while checking b[j]: store steps monsters eating
*/
void epidemicMotrospolis(vulli &a, vulli &b) {
    int n = a.size();
    int k = b.size();
    bool ans = true;
    vplc steps;
    vulli prefix(n+1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + a[i-1];
    }
    int pos = 0;
    int j = 0;
    for (int i = 0; i <= n; i++) {
        if (prefix[i]-prefix[pos] > b[j]) {
            ans = false;
            break;
        }
        else if (prefix[i] - prefix[pos] == b[j]) {
            pos = i;
            j++;
        }
    }
    if (ans) cout << "YES";
    else cout << "NO";
    cout << endl;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int n, k;
    while (cin >> n) {
        vulli a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        vulli b(k);
        for(int i = 0; i < k; i++) {
            cin >> b[i];
        }
        epidemicMotrospolis(a,b);
    }
#endif
    return 0;
}
