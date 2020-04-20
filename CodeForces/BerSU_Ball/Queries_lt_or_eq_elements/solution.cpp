// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/600/B
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Read input
void read_array(string line, vector<long> &nums) {
    stringstream ss(line);
    long num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}

// Print out input
void print_array(vector<long> &nums) {
    for (long i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    create a map to store counts of each value in b
    then sort a and b in order to use two-pointer technique
    complexity O(N+M)
*/
void query(vector<long> &a, vector<long> &b) {
    int n = a.size();
    int m = b.size();
    sort(a.begin(), a.end());
    map<long, int> mp;
    for (long val : b) {
        mp[val] = 0;
    }
    map<long, int>::iterator it;
    int i = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
        while (a[i] <= it->first && i < n) i++;
        it->second = i;
    }
    for (long val : b) {
        cout << mp[val] << " ";
    }
    puts("");
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int m, n;
    while (cin >> m >> n)
    {
        cin.ignore();
        string line;
        getline(cin, line);
        vector<long> a;
        read_array(line, a);

        getline(cin, line);
        vector<long> b;
        read_array(line, b);
        
        query(a, b);
    }
#endif
    return 0;
}
