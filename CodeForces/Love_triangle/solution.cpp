// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/939/A

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define ulli unsigned long long int
#define vulli vector<ulli>
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

// Read input
void read_array(string line, vector<int> &nums) {
    stringstream ss(line);
    int num;
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
check g[g[g[i]]] == i
*/
void addEdge(vvi &graph, int v, int u) {
    graph[v].push_back(u);
}

int getCrush(vvi &graph, int i) {
    return graph[i][0];
}

void loveTriangle(vi arr) {
    int n = arr.size();
    vvi g(n, vi());
    for (int i = 0; i < n; i++) {
        addEdge(g, i, arr[i]-1);
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        int crush = getCrush(g, getCrush(g, getCrush(g,i)));
        if (crush == i) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "YES";
    else cout << "NO";
    cout << endl;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int n;
    string line;
    while (cin >> n)
    {
        cin.ignore();
        getline(cin, line);
        vector<int>nums;
        read_array(line, nums);
        loveTriangle(nums);
    }
#endif
    return 0;
}
