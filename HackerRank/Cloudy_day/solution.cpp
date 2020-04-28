// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/cloudy-day/problem
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

#define ulli unsigned long long int

using namespace std;

// Read input
void read_array(string line, vector<long> &nums)
{
    stringstream ss(line);
    long num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

// Print out input
void print_array(vector<long> &nums)
{
    for (long i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    Use sweep line technique to determine number of people under each cloud.
        - Create a map of events whose keys are coordinates:
            - y[i] - r[i] : the i-th cloud active.
            - y[i] + r[i] + 1: the i-th cloud inactive.
            - x[j]: the j-th town.
        - The values of the map are sorted lists of pairs <key, value>
    Regard to greedy, choose the cloud which covers the most population.
*/
typedef pair<long,long> pll;
typedef pair<pll, long> plll;
#define vpll vector<pll>
map<long, vpll> events;
#define vl vector<long>

long maximumPeople(vl p, vl x, vl y, vl r)
{
    long n = p.size();
    long m = y.size();
    for (int i = 0; i < n; i++) {
        events[x[i]].push_back(pair(2, p[i]));
    }
    for (int i = 0; i < m; i++) {
        events[y[i]-r[i]].push_back(pair(1, i));
        events[y[i]+r[i]+1].push_back(pair(-1, i));
    }
    map<long, vpll>::iterator it;
    set<long> active;
    vector<long> underPop(m);
    long sunnyPop = 0;
    for (it = events.begin(); it != events.end(); it++) {
        long coord = it->first;
        vpll lst_event = it->second;
        sort(lst_event.begin(), lst_event.end());
        vpll::iterator e;
        for (e = lst_event.begin(); e != lst_event.end(); e++) {
            if (e->first == -1) {
                active.erase(e->second);
            }
            else if (e->first == 1) {
                active.insert(e->second);
            }
            else {
                if (active.size() == 1) {
                    underPop[*active.begin()] += e->second;
                }
                else if (active.size() == 0) {
                    sunnyPop += e->second;
                }
            }
        }
    }
    long mx = 0;
    for (long x : underPop) {
        mx = max(mx, x);
    }
    return sunnyPop+mx;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int n, m;
    string line;
    while (cin >> n)
    {
        cin.ignore();
        vl p, x;
        getline(cin, line);
        read_array(line, p);
        getline(cin, line);
        read_array(line, x);
        cin >> m;
        cin.ignore();
        vl y, r;
        getline(cin, line);
        read_array(line, y);
        getline(cin, line);
        read_array(line, r);
        cout << maximumPeople(p, x, y, r) << endl;
    }
#endif
    return 0;
}
