// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1327/B

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
    Use graph to store choices of each princess
    Use array to store matches
    Use greedy to create matches
*/
void solve(vvi &graph, int n) {
    vi princesses(n, 0);
    vi princes(n, 0);
    for (int i = 0; i < n; i++) {
        for (int p : graph[i]) {
            if (princes[p-1] == 0) {
                princesses[i] = p;
                princes[p-1] = i+1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (princesses[i] == 0) {
            cout << "IMPROVE" << endl;
            for (int j = 0; j < n; j++) {
                if (princes[j] == 0) {
                    cout << i+1 << " " << j+1 << endl;
                    return;
                }
            }
        }
    }
    cout << "OPTIMAL" << endl;
}

int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    string line;
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vvi graph(n, vi());
        cin.ignore();
        for (int j = 0; j < n; j++) {
            vi nums;
            getline(cin, line);
            readArray(line, nums);
            for (int i = 1; i <= nums[0]; i++) {
                graph[j].push_back(nums[i]);
            }
        }
        solve(graph, n);
    }
#endif
    return 0;
}
