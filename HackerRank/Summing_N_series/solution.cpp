// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/summing-the-n-series/problem
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Read input
void read_array(string line, vector<int> &nums) {
    stringstream ss(line);
    int num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}

// Print out input
void print_array(vector<int> &nums) {
    for (int i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
Write your solution here
*/
int summingSeries(long n)
{
    long S = 0;
    for (long i = 1; i <= n; i++) {
        S += (i^2 - (i-1)^2) % (10^9 + 7);
    }
    return S % (10^9 + 7);
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = summingSeries(n);

        cout << result << "\n";
    }
#endif
    return 0;
}
