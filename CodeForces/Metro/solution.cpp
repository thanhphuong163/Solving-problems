// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1055/A

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


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

/*
Create graph and use dfs to find final destination
Note: use visited to avoid cycle
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
            int ans = 0;
            for (int i = 0; i < metro[station].size(); i++) {
                ans += checkAlice(metro, visited, metro[station][i], alice);
            }
            return ans;
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
