// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/734/C
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define ulli unsigned long long int
#define vulli vector<ulli>

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
Write your solution here
*/
ulli preparePotions(ulli s, vulli a, vulli b, vulli c, vulli d) {
    ulli m = a.size();
    ulli k = c.size();
    ulli cost = INT64_MAX;
    // Your code here

    return cost;
}

    // #define DEBUG_MODE
    int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    ulli n,m,k,x,s;
    while (cin >> n >> m >> k)
    {
        cin >> x >> s;
        cin.ignore();
        vector<ulli> a,b,c,d;
        getline(cin, line);
        read_array(line, a);
        getline(cin, line);
        read_array(line, b);
        getline(cin, line);
        read_array(line, c);
        getline(cin, line);
        read_array(line, d);
        cout << preparePotions(s,a,b,c,d) << endl;
    }
#endif
    return 0;
}
