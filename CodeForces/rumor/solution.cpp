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
#define vvi vector<vi>
#define vlli vector<lli>
#define vvlli vector<vlli>

#define DEBUG_MODE 0
#if DEBUG_MODE == 1
    #define imie(...) "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "]"
    #define LOG(variable) cout << imie(variable) << endl
#else
    #define LOG(msg)
#endif

using namespace std;

// Read input
void readArray(string line, vector<lli> &nums) {
    stringstream ss(line);
    lli num;
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
 create a graph of friends
 find the character who has the lowest cost to bribe in each connected component
 use a heard_rumor[] to store people who heard the rumor
 total cost will be the sum of lowest cost character in each connected component
*/


int explore(vvlli &graph, vlli &c, lli v, vector<bool> &visited) {
    visited[v] = true;
    lli cost = c[v];
    for (lli i = 0; i < graph[v].size(); i++) {
        if (!visited[graph[v][i]]) {
            lli tmp = explore(graph, c, graph[v][i], visited);
            cost = cost < tmp ? cost : tmp;
        }        
    }
    return cost;
}

int spread_rumor(vlli &c, vlli &x, vlli &y) {
    lli n = c.size();
    vvlli graph = vvlli(n, vlli());
    lli m = x.size();
    for (lli i = 0; i < m; i++) {
        graph[x[i]-1].push_back(y[i]-1);
        graph[y[i]-1].push_back(x[i]-1);
    }
    lli cost = 0;
    vector<bool> heard_rumor = vector<bool>(n, false);
    for (lli i = 0; i < n; i++) {
        if (!heard_rumor[i]) {
            cost += explore(graph, c, i, heard_rumor);
        }
    }
    return cost;
}
int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    lli n, m;
    cin >> n >> m;
    cin.ignore();
    string line;
    vlli c;
    getline(cin, line);
    readArray(line, c);
    vlli x, y;
    for (lli i = 0; i < m; i++) {
        lli xi, yi;
        cin >> xi >> yi;
        x.push_back(xi);
        y.push_back(yi);
    }
    cout << spread_rumor(c, x, y) << endl;
#endif
    return 0;
}
