// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1257/D
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define ulli unsigned long long int
#define vulli vector<ulli>
#define pll pair<ulli, ulli>
#define vpll vector<pll>

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums)
{
    stringstream ss(line);
    ulli num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

// Print out input
void print_array(vector<ulli> &nums)
{
    for (ulli i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    Greedy approach: Kill as many monsters as possible everyday.
    So we create a array bst with size of max endurance, this is a list of candidates for each day.
    Each entry stores hero's maximum power whose endurance greater than or equal to the array's index.
    Now, suppose we've already killed pos monsters. If a[pos+1] > bts[pos] then return -1,
    otherwise, we kill at least x = 1 monster. All we need to do is increasing value x ultil condition
    max_{pos<i<pos+x} holds.
*/

int killMonster(vulli a, vulli p, vulli s)
{
    ulli n = a.size();
    ulli m = p.size();
    ulli maxEndurance = 0;
    for (ulli i = 0; i < m; i++) {
        maxEndurance = max(maxEndurance, s[i]);
    }
    vulli bst(maxEndurance+2);
    for (ulli i = 0; i < m; i++) {
        bst[s[i]] = max(bst[s[i]], p[i]);
    }
    for (ulli i = bst.size()-2; i >= 0; i--) {
        bst[i] = max(bst[i], bst[i+1]);
    }

    // Play
    int days = 0;
    ulli pos = 0;
    while (pos < n) {
        days++;
        ulli npos = pos;
        ulli mx = 0;
        while(true) {
            mx = max(mx, a[npos]);
            if (mx > bst[npos-pos+1]) break;
            npos++;
        }
        if (npos == pos) return -1;
        pos = npos;
    }
    return days;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int t;
    cin >> t;
    string line;
    while (t--)
    {
        ulli n, m;
        cin >> n;
        vulli a(n);
        for (ulli i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        vulli p(m), s(m);
        for (ulli i = 0; i < m; i++)
            cin >> p[i] >> s[i];
        cout << killMonster(a,p,s) << endl;
    }
#endif
    return 0;
}
