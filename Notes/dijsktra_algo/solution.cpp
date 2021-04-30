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
void display_graph(vvi &graph) {
    for (vi e : graph)
    {
        cout << e[0] << "->" << e[1] << ": " << e[2] << endl;
    }
}
void find_shortest_path(vvi &graph, int source){
    int n = graph.size();
    display_graph(graph);
}

int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    int n, s;
    cin >> n >> s;
    cin.ignore();
    vvi graph;
    string line;
    int u, v, w;
    while (cin >> u >> v >> w)
    {
        cin.ignore();
        vi e = {u-1, v-1, w};
        graph.push_back(e);
    }
    find_shortest_path(graph, s-1);
#endif
    return 0;
}
