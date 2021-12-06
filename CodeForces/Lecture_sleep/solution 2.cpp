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
    Use two-pointer technique
*/
long wakeMishka(vector<long> &a, vector<long> &t, long k)
{
    long n = a.size();
    long fix = 0;
    for (int i = 0; i < n; i++)
    {
        fix += a[i] * t[i];
    }
    for (int i = 0; i < k; i++)
    {
        fix += a[i] * (t[i] ^ (long)1);
    }

    long maxTheorem = fix;
    long tmp = fix;
    for (int i = 1; i < n - k + 1; i++)
    {
        long oldStart = a[i - 1] * (t[i - 1] ^ (long)1);
        long newEnd = a[i + k - 1] * (t[i + k - 1] ^ (long)1);
        tmp += newEnd - oldStart;
        maxTheorem = max(maxTheorem, tmp);
    }
    return maxTheorem;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    vector<long> a{76, 83, 17, 34, 24, 46, 95};
    vector<long> t{0, 1, 0, 1, 1, 1, 0};
    long n = 7;
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
