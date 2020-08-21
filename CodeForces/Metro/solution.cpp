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
Create graph and use dfs to find final destination
*/
bool checkAlice(vvi &metro, vi &visited, int station, int alice) {
    if (visited[station]) {
        visited[station]--;
        if (station == alice)
        {
            return true;
        }
        else
        {
            for (int i = 0; i < metro[station].size(); i++) {
                return checkAlice(metro, visited, metro[station][i], alice);
            }
        }
    }
    return false;
}

void checkRoute(vi &forward, vi &backward, int alice) {
    int n = forward.size();
    vvi metro(n, vi());
    vi visited(n,0);
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (forward[i]) {
            visited[i]++;
            if (prev != -1) {
                metro[prev].push_back(i);
            }
            prev = i;
        }
    }
    prev = -1;
    for (int i = n-1; i >= 0; i--) {
        if (backward[i]) {
            visited[i]++;
            if (prev != -1) {
                metro[prev].push_back(i);
            }
            prev = i;
        }
    }
    if (checkAlice(metro, visited, 0, alice)) cout << "YES";
    else cout << "NO";
    cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < metro[i].size(); j++)
    //     {
    //         cout << metro[i][j] << " ";
    //     }
    //     cout << endl;
    // }
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
        checkRoute(forward, backward, alice-1);
    }
#endif
    return 0;
}
