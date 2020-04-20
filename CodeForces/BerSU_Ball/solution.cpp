// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/489/B
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Read input
void read_array(string line, vector<int> &nums)
{
    stringstream ss(line);
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

// Print out input
void print_array(vector<int> &nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    abs(b[i] - g[j]) <= 1 ==> make pair
    change value of one of two into INT_MAX
*/
int getMaxPairs(vector<int> boys, vector<int> girls) {
    int n = boys.size();
    int m = girls.size();
    int cntPair = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (abs(boys[i] - girls[j]) <= 1) {
                cntPair++;
                girls[j] = INT_MAX;
                break;
            }
        }
    }
    return cntPair;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int m;
    while (cin >> m)
    {
        cin.ignore();
        string line;
        getline(cin, line);
        vector<int> boys;
        read_array(line, boys);

        int n;
        cin >> n;
        cin.ignore();
        string line;
        getline(cin, line);
        vector<int> girls;
        read_array(line,girls);

        cout << getMaxPairs(boys, girls) << endl;
    }
#endif
    return 0;
}
