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
struct my_cmp {
    constexpr bool operator()(vi const &a, vi const &b) const noexcept {
    return a[1] > b[1];
    }
};
void display_graph(vvi &graph) {
    for (vi e : graph)
    {
        cout << e[0] << "->" << e[1] << ": " << e[2] << endl;
    }
}
void find_shortest_path(vvpii &graph, int source){
    int n = graph.size();
    priority_queue<vi, vvi, my_cmp> q;
    vi dist = vi(n, INF);
    dist[source] = 0;
    for (int i = 0; i < n; i++) {
        q.push({i, dist[i]});
    }
    for (int i = 0; i < n-1; i++) {
        vi u = q.top();
        q.pop();
        for (auto e : graph[u[0]]) {
            if (dist[e.first] > dist[u[0]] + e.second) {
                dist[e.first] = dist[u[0]] + e.second;
                q.push({e.first, dist[e.first]});
            }
        }
    }
    printArray(dist);
}

int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    int n, s;
    cin >> n >> s;
    cin.ignore();
    vvpii graph = vvpii(n);
    string line;
    int u, v, w;
    while (cin >> u >> v >> w)
    {
        cin.ignore();
        graph[u-1].push_back(make_pair(v-1, w));
    }
    find_shortest_path(graph, s-1);
#endif
    return 0;
}
