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
bool comp_node(vi a, vi b) {
    return a.size() > b.size();
}

int remove_toy(vi &v, vi &x, vi &y) {
    int m = x.size();
    int n = v.size();
    int energy = 0;
    for (int i = 0; i < m; i++) {
        if (v[x[i]-1] < v[y[i]-1]) {
            energy += v[x[i]-1];
        }
        else {
            energy += v[y[i]-1];
        }
        cout << energy << endl;
        //energy += v[x[i]] < v[y[i]] ? v[x[i]] : v[y[i]];
    }
    return energy;
}
int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    int n, m;
    cin >> n >> m;
    cin.ignore();
    string line;
    getline(cin, line);
    vector<int> v;
    readArray(line, v);
    vector<int> x, y;
    for (int i = 0; i < m; i++){
        int xi, yi;
        cin >> xi >> yi;
        x.push_back(xi);
        y.push_back(yi);
    }
    cout << remove_toy(v, x, y) << endl;
#endif
    return 0;
}
