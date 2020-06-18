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
    What is the fast solution for this problem?
    Using greedy approach:
    We iterate all first type of spell, then find the second type of spell using binary search
    O(m*logk)
*/
ulli preparePotions(ulli n, ulli x, lli s, vlli &a, vlli &b, vlli &c, vlli &d) {
    ulli m = a.size()-1;
    ulli k = c.size()-1;
    ulli cost = x*n;
    for (ulli i = 0; i <= m; i++) {
        lli remain_mana = s - b[i];
        if (remain_mana < 0) continue;  // There are not enough manapoints for this first spell
        // Using binary search to find the second spell
        ulli l = 0;
        ulli r = k;
        while (l < r)
        {
            ulli mid = l + (r - l + 1) / 2;
            if (remain_mana >= d[mid])
                l = mid;
            else
                r = mid - 1;
        }
        cost = min(cost, (n - c[l]) * a[i]);
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
        vector<lli> a(m+1),b(m+1),c(k+1),d(k+1);
        a[0] = x;
        b[0] = 0;
        c[0] = 0;
        d[0] = 0;
        for (int i = 1; i <= m; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        for (int i = 1; i <= k; i++)
            cin >> c[i];
        for (int i = 1; i <= k; i++)
            cin >> d[i];
        cout << preparePotions(n,x,s,a,b,c,d) << endl;
    }
#endif
    return 0;
}
