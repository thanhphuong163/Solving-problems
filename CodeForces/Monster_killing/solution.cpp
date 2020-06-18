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
    Using greedy algorithm:
    - Sort heroes in order of non-increasing powers then endurances
    - Each day, choose one which the most power and endurance.
*/
bool desc_order(const pll &a, const pll &b)
{
    return ((a.first >= b.first) && (a.second >= b.second));
}

int killMonster(vulli a, vulli p, vulli s)
{
    ulli n = a.size();
    ulli m = p.size();
    vpll heroes;
    for (ulli i = 0; i < m; i++)
    {
        heroes.push_back(make_pair(p[i], s[i]));
    }
    // sort in descending order
    sort(heroes.begin(), heroes.end(), desc_order);

    // Play
    int days = 0;
    for (pll hero : heroes)
    {
        cout << hero.first << " " << hero.second << endl;
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
