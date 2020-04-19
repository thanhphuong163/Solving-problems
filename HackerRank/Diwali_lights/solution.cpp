// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/diwali-lights/problem
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

#define ulli unsigned long long int

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
    2^N - 1
    N/64
    N = 100
    2^(63+37) - 1 = 2^63 * 2^37 - 1
*/
long lights(int n)
{
    long c = (long)1e5;
    ulli a = (ulli)(powl(2, 63)) % c;
    int k = (int)n / 63;
    int r = n % 63;
    ulli b = (ulli)(powl(2, r)) % c;
    ulli res = 1;
    for (int i = 0; i < k; i++)
    {
        res = (res * a) % c;
    }
    res = (res * b) % c;
    return res - 1;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    long result = lights(1000);
    cout << result << "\n";
#else
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = lights(n);

        cout << result << "\n";
    }
#endif
    return 0;
}
