// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 

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
#define pii pair<int, int>
#define vpii vector<pii>
#define vvpii vector<vpii>
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
void readArray(string line, vector<ulli> &nums) {
    stringstream ss(line);
    ulli num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}
void readArray(string line, vi &nums) {
    stringstream ss(line);
    int num;
    while(ss >> num) {
        nums.push_back(num);
    }
}

// Print array
void printArray(vulli &nums) {
    for (ulli num : nums)
    {
        cout << num << " ";
    }
    puts("");
}
void printArray(vi &nums) {
    for(int num : nums) {
        cout << num << " ";
    }
    puts("");
}

/*
    Dijkstra Algorithm
*/
void add_edge(vvpii graph, int u, int v, int w) {
    graph[u].push_back(make_pair(v, w));
}
void find_shortest_path(vvpii graph, int source){
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (auto e : graph[i]) {
            cout << i << " " << e.first << " " << e.second << endl;
        }
    }
}

int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    int n, s;
    cin >> n >> s;
    cin.ignore();
    vvpii graph = vvpii(n, vpii());
    string line;
    int u, v, w;
    while (cin >> u >> v >> w)
    {
        cin.ignore();
        add_edge(graph, u-1, v-1, w);
        find_shortest_path(graph, s);
    }
#endif
    return 0;
}
