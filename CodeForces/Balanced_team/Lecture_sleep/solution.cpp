// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/961/B
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define ulli unsigned long long int
#define max(a, b) (a > b ? a : b)

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
void prulli_array(vector<long> &nums)
{
    for (long i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    Use brute force O(n*k)
*/
long wakeMishka(vector<long> &a, vector<long> &t, long k)
{
    long n = a.size();
    long maxTheorem = 0;
    long fix = 0;
    for (long i = 0; i < n; i++)
    {
        fix += a[i] * t[i];
    }
    for (long i = 0; i < n - k + 1; i++)
    {
        long sum = 0;
        for (long j = 0; j < k; j++)
        {
            sum += a[i + j] * (t[i + j] ^ (long)1);
        }
        maxTheorem = max(maxTheorem, fix+sum);
    }
    return maxTheorem;
}

#define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    vector<long> a{1, 3, 5, 2, 5, 4};
    vector<long> t{1, 1, 0, 1, 0, 0};
    long n = 6;
    long k = 3;
    cout << wakeMishka(a, t, k) << endl;
#else
    string line;
    long n, k;
    while (cin >> n >> k)
    {
        cin.ignore();
        getline(cin, line);
        vector<long> a;
        read_array(line, a);
        getline(cin, line);
        vector<long> t;
        read_array(line, t);
        cout << wakeMishka(a, t, k) << endl;
    }
#endif
    return 0;
}
