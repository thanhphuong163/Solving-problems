// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/cloudy-day/problem
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
    Iterate each town:
        - under_cloud = -1
        - Iterate each cloud:
            - if (y[cloud] - r[cloud] <= x[town] && x[town] <= y[cloud] + r[cloud]) then 
                - if under_cloud == -1 then under_cloud = cloud
                - else under_cloud = -2;
        - If under_cloud == -1 then sunny_pop += p[town]
        - If under_cloud != -2 then pop_cloud[under_cloud] += p[town]
    Iterate each cloud:
        - maxPopulation = max(pop_cloud[cloud], maxPopulation)
    return sunny_pop + maxPopulation

*/
long maximumPeople(vulli p, vulli x, vulli y, vulli r)
{
    long n = p.size();
    long m = y.size();
    ulli sunnyPeople = 0;
    vulli cloudPeople(m, 0);
    for (long town = 0; town < n; town++) {
        long underCloud = -1;
        for (int cloud = 0; cloud < m; cloud++) {
            if (y[cloud] - r[cloud] <= x[town] && x[town] <= y[cloud] + r[cloud]) {
                if (underCloud == -1)
                    underCloud = cloud;
                else
                    underCloud = -2;    // under more than one cloud
            }
        }
        if (underCloud == -1)
            sunnyPeople += p[town];
        if (underCloud != -2)
            cloudPeople[underCloud] += p[town];
    }
    ulli maxPeople = 0;
    for (long cloud = 0; cloud < m; cloud++) {
        maxPeople = max(maxPeople, cloudPeople[cloud]);
    }
    return (long) maxPeople+sunnyPeople;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    ulli n, m;
    string line;
    while (cin >> n)
    {
        cin.ignore();
        vulli p, x;
        getline(cin, line);
        read_array(line, p);
        getline(cin, line);
        read_array(line, x);
        cin >> m;
        cin.ignore();
        vulli y, r;
        getline(cin, line);
        read_array(line, y);
        getline(cin, line);
        read_array(line, r);
        cout << maximumPeople(p, x, y, r) << endl;
    }
#endif
    return 0;
}
