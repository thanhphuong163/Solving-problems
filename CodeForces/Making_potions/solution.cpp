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
#define lli long long int
#define vulli vector<ulli>
#define vlli vector<lli>
#define INF INT64_MAX

using namespace std;

// Read input
void read_array(string line, vector<lli> &nums) {
    stringstream ss(line);
    lli num;
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
    The below code is a bruteforce solution
*/
ulli preparePotions_bruteforce(ulli n, ulli x, lli s, vlli &a, vlli &b, vlli &c, vlli &d) {
    ulli m = a.size();
    ulli k = c.size();
    ulli cost = x*n;
    // Your code here
    for (int i = 0; i < m; i++) {
        int j = k-1;
        while (j >= 0) {
            if (s-b[i] >= d[j]) {
                cost = min(cost, (n-c[j])*a[i]);
                break;
            }
            j--;
        }
        if (s - b[i] >= 0)
            cost = min(cost, n * a[i]);
    }
    return cost;
}

/*
    What is the fast solution for this problem?
    Using greedy approach:
    We iterate all first type of spell, then find the second type of spell using binary search
    O(m*logk)
*/
ulli preparePotions(ulli n, ulli x, lli s, vlli &a, vlli &b, vlli &c, vlli &d) {
    ulli m = a.size();
    ulli k = c.size();
    ulli cost = x*n;
    for (int i = 0; i < m; i++) {
        lli remain_mana = s - b[i];
        if (remain_mana < 0) continue;  // There are not enough manapoints for this first spell
        if (remain_mana < d[0]) {   // There are not enough manapoints for any second spell
            cost = min(cost, n*a[i]);
        }
        else {
            // Using binary search to find the second spell
            ulli l = 0;
            ulli r = k;
            while (l < r) {
                ulli mid = l+(r-l+1)/2;
                if (remain_mana >= d[mid]) l = mid;
                else r = mid-1;
            }
            cost = min(cost, (n-c[l])*a[i]);
        }
    }
    return cost;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    ulli n,m,k,x;
    lli s;
    while (cin >> n >> m >> k)
    {
        cin >> x >> s;
        cin.ignore();
        vector<lli> a,b,c,d;
        getline(cin, line);
        read_array(line, a);
        getline(cin, line);
        read_array(line, b);
        getline(cin, line);
        read_array(line, c);
        getline(cin, line);
        read_array(line, d);
        cout << preparePotions(n,x,s,a,b,c,d) << endl;
    }
#endif
    return 0;
}
