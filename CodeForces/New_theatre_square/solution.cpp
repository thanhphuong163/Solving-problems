// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1359/B
// Submit: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#define ulli unsigned long long int

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
void print_array(vector<int> &nums) {
    for (int i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    Using greedy algorithm:
        - If square is white, then check the next square:
            - If it is white then, cost += min(2*x, y) and jump 2 steps
            - Else use the one tie
*/
int paveTheatre(vector<int> &params, vector<string> theatre) {
    int n,m,x,y;
    int ans = 0;
    n = params[0];
    m = params[1];
    x = params[2];
    y = params[3];
    
    for (int i = 0; i < n; i++) {
        int j = 0;
        string row = theatre[i];
        while (j < m) {
            if (row[j] == '.') {
                if (row[j+1] == '.') {
                    ans += min(2*x, y);
                    j += 2;
                }
                else {
                    ans += x;
                    j++;
                }
            }
            else {
                j++;
            }
        }
    }
    return ans;
}


// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int t;
    cin >> t;
    cin.ignore();
    string line;
    while (t--) {
        getline(cin, line);
        vector<int> params;
        vector<string> theatre;
        read_array(line, params);
        int n = params[0];
        while(n--) {
            getline(cin, line);
            theatre.push_back(line);
        }
        cout << paveTheatre(params, theatre) << endl;
    }
#endif
    return 0;
}
