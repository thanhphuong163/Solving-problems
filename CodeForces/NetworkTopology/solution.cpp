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
#define pii pair<int,int>
#define vpii vector<pii>

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
Write your solution here
*/
bool isBus(vi &vertices) {
    int count = 0;
    int n = vertices.size();
    for (int i = 0; i < n; i++) {
        if (vertices[i] == 1) count++;
        if (vertices[i] != 2) return false;
    }
    if (count == 2) return true;
    else return false;
}

bool isRing(vi &vertices) {
    int n = vertices.size();
    for (int i = 0; i < n; i++) {
        if (vertices[i] != 2) return false;
    }
    return true;
}

bool isStar(vi &vertices) {
    int n = vertices.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vertices[i] != 1 && vertices[i] != n-1) return false;
        if (vertices[i] == n-1) count++;
    }
    if (count == 1) return true;
    else return false;
}

void checkNetworkType(int n, vpii &edgeList) {
    vi vertices(n, 0);
    cout << edgeList.size() << endl;
    for (pii edge : edgeList) {
        cout << edge.first << " " << edge.second << endl;
        vertices[edge.first]++;
        vertices[edge.second]++;
    }
    printArray(vertices);
    if (isBus(vertices))
        cout << "bus topology\n";
    else if (isRing(vertices))
        cout << "ring topology\n";
    else if (isStar(vertices))
        cout << "star topology\n";
    else
        cout << "unknown topology\n";
}

int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    string line;
    int n, m;
    while (cin >> n >> m)
    {
        vpii edgeList(m);
        int v,u;
        for (int i = 0; i < m; i++) {
            cin >> v >> u;
            edgeList.push_back(pii(v-1,u-1));
        }
        checkNetworkType(n, edgeList);
    }
#endif
    return 0;
}
