// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1020/B

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define ulli unsigned long long int
#define lli long long int
#define vulli vector<ulli>
#define vi vector<int>
#define vvi vector<vi>

#define DEBUG_MODE 0
#if DEBUG_MODE == 1
    #define imie(...) "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "]"
    #define LOG(variable) cout << imie(variable) << endl
#else
    #define LOG(msg)
#endif

using namespace std;

// Read input
void readArray(string line, vi &nums) {
    stringstream ss(line);
    int num;
    while(ss >> num) {
        nums.push_back(num);
    }
}

// Print array
void printArray(vi &nums) {
    for(int num : nums) {
        cout << num << " ";
    }
    puts("");
}

/*
    graph and dfs, 
    use a vector<int> mark to count number of holes on each student's badge
*/
void putAHole(int n, vi &p) {
    vi graph(n);
    for (int i = 0; i < n; i++) {
        graph[i] = p[i]-1;
    }
    vi ans(n);
    for (int i = 0; i < n; i++) {
        vi mark(n, 0);
        int pos = i;
        while (mark[pos] < 2) {
            mark[pos]++;
            pos = graph[pos];
        }
        ans[i] = pos+1;
    }
    printArray(ans);
}

int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    string line;
    int n;
    while (cin >> n)
    {
        cin.ignore();
        getline(cin, line);
        vi nums;
        readArray(line, nums);
        putAHole(n, nums);
    }
#endif
    return 0;
}
