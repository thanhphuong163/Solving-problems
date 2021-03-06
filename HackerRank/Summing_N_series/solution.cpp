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
    T_n = n^2 - (n-1)^2
    S_n = T_1 + T_2 + ... + T_{n-1} + T_n
        = 1   + 4 - 1 + ... + (n-1)^2 - (n-2)^2 + n^2 - (n-1)^2
        = n^2
    use unsigned long long int (8 bytes)
*/
int summingSeries(long n)
{
    long c = (long)1e9 + 7;
    unsigned long long int a = n%c;
    unsigned long long int res = (a*a)%c;
    return res;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    int result = summingSeries(10000000);
    cout << result << "\n";
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
