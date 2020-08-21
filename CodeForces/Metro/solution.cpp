// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1055/A

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
#define pii pair<int,int>
#define vpii vector<pii>

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
Use dfs to find the 
*/
// bool checkAlice(vvi &metro, int station, int alice) {
//     if (station == alice) {
//         return true;
//     }
//     else if (metro[station].size() == 0) {
//         return false;
//     }
//     else {
//         for (int i = 0; i < metro[station].size(); i++) {
//             return checkAlice(metro, metro[station][i], alice);
//         }
//     }
// }

void checkRoute(vi &forward, vi &backward, int alice) {
    int n = forward.size();
    cout << n << endl;
    vvi metro(n, vector<int>());
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (forward[i]) {
            if (prev != -1) metro[prev].push_back(i);
            prev = i;
        }
    }
    prev = -1;
    for (int i = n-1; i >= 0; i++) {
        if (backward[i]) {
            if (prev != -1) metro[prev].push_back(i);
            prev = i;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < metro[i].size(); j++) {
            cout << metro[i][j] << " ";
        }
        cout << endl;
    }
    // if (checkAlice(metro, 0, alice)) cout << "YES";
    // else cout << "NO";
    // cout << endl;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    int n, alice;
    while (cin >> n >> alice)
    {
        cin.ignore();
        getline(cin, line);
        vector<int> forward, backward;
        read_array(line, forward);
        getline(cin, line);
        read_array(line, backward);
        checkRoute(forward, backward, alice);
    }
#endif
    return 0;
}
