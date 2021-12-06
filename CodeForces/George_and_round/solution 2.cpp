// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/387/B
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
    Check if there are any prepared problems having complexity greater than required problems.
*/
int minProblem(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int j = 0;
    int a_len = a.size();
    int b_len = b.size();
    int n = a_len;
    while (j < b_len)
    {
        if (b[j] >= a[i])
        {
            n--;
            i++;
        }
        if (i >= a_len)
            return 0;
        j++;
    }
    return n;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int n, m;
    while (cin >> n >> m)
    {
        cin.ignore();
        string line;
        getline(cin, line);
        vector<int> a;
        read_array(line, a);
        getline(cin, line);
        vector<int> b;
        read_array(line, b);
        cout << minProblem(a, b) << endl;
    }
#endif
    return 0;
}
