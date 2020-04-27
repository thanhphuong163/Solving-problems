// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/pylons/problem
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
void print_array(vector<ulli> &nums)
{
    for (ulli i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    Use Greedy:
    - The first tower must be placed at x < k
    - The next tower must be placed at x+k <= i < x+2k
    - If we cannot place tower in this way, then return -1
    - If x+k > n, then end the procedure.
    7 2
    0 1 1 1 1 0 1
    ==> 3 at indices 1 4 6
*/
int pylons(int k, vector<int> arr)
{
    int n = arr.size();
    int x = -k;
    int i = x + 2 * k - 1;
    int trans = 0;
    while (i < n)
    {
        trans++;
        while (x + k <= i && arr[i] == 0)
        {
            i--;
        }
        if (i < x + k)
            return -1;
        else
        {
            x = i;
            i = x + 2 * k - 1;
            if (x+k<n && i >= n) {
                i = n-1;
            }
        }
    }
    return trans;
}

// #define DEBUG_MODE

int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    vector<int> arr = {0, 1, 1, 0, 1, 0, 0};
    cout << pylons(2, arr) << endl;
#else
    int n, k;
    string line;
    while (cin >> n >> k)
    {
        cin.ignore();
        getline(cin, line);
        vector<int> arr;
        read_array(line, arr);
        cout << pylons(k, arr) << endl;
    }

#endif
    return 0;
}
