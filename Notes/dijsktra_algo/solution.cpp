// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
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

const int INF = 99999999;

#define DEBUG_MODE 0
#if DEBUG_MODE == 1
    #define imie(...) "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "]"
    #define LOG(variable) cout << imie(variable) << endl
#else
    #define LOG(msg)
#endif

using namespace std;

// Read input
void readArray(string &line, vector<ulli> &nums) {
    stringstream ss(line);
    ulli num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}
void readArray(string &line, vi &nums) {
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
struct my_comp {
    constexpr bool operator()(pii const &a, pii const &b) const noexcept {
        return a.second > b.second;
    }
};
#define pqii priority_queue<pii, vector<pii>, my_comp>
#define adj_list vector<pqii>

void add_edge(adj_list &graph, int u, int v, int w) {
    graph[u].push(make_pair(v, w));
}
void find_shortest_path(adj_list &graph, int source){
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        while (!graph[i].empty()) {
            pii e = graph[i].top();
            cout << i << "->" << e.first << ": " << e.second << endl;
            graph[i].pop();
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
    adj_list graph = adj_list(n);
    string line;
    int u, v, w;
    while (cin >> u >> v >> w)
    {
        cin.ignore();
        add_edge(graph, u-1, v-1, w);
    }
    find_shortest_path(graph, s-1);
#endif
    return 0;
}
