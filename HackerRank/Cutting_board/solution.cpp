// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 
// Submit: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define ulli unsigned long long int

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums) {
    stringstream ss(line);
    ulli num;
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
    sort cost_x[] and cost_y[] descending order
    x_pieces = 1
    y_pieces = 1
    use two-pointer technique to choose vertical or horizontal cut:
    - if x cut, then cost = cost_x[i] * y_pieces; y_pieces++;
    - if y cut, then cost = cost_y[j] * x_pieces; x_pieces++;
    x: 4 3 2 1 1
       ^
    y: 4 2 1
       ^
    x_pieces = 1
    y_pieces = 1
*/
ulli boardCutting(vector<ulli> cost_y, vector<ulli> cost_x)
{
    ulli c = 1e9+7;
    ulli res = 0;
    sort(cost_x.begin(), cost_x.end(), greater<int>());
    sort(cost_y.begin(), cost_y.end(), greater<int>());
    long long n = cost_x.size();
    long long m = cost_y.size();
    long long x = 0;
    long long y = 0;
    long long x_pieces = 1;
    long long y_pieces = 1;
    while (x < n || y < m) {
        if (cost_x[x] > cost_y[y]) {
            res += (cost_x[x] * y_pieces) % c;
            x_pieces++;
            x++;
        }
        else if (cost_x[x] < cost_y[y]) {
            res += (cost_y[y] * x_pieces) % c;
            y_pieces++;
            y++;
        }
        else {
            long long cost1 = cost_y[y] * x_pieces;
            long long cost2 = cost_x[x] * y_pieces;
            if (cost1 < cost2) {
                res += cost1 % c;
                y++;
                y_pieces++;
            }
            else {
                res += cost2 % c;
                x++;
                x_pieces++;
            }
        }
    }
    return res % c;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    int q;
    cin >> q;
    cin.ignore();
    while (q--)
    {
        long long n, m;
        cin >> n >> m;
        cin.ignore();
        getline(cin,line);
        vector<ulli> cost_y;
        read_array(line, cost_y);
        getline(cin, line);
        vector<ulli> cost_x;
        read_array(line, cost_x);
        cout << boardCutting(cost_y, cost_x) << endl;
    }
#endif
    return 0;
}
