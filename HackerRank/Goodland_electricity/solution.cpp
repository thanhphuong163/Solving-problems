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
    6 2
    0 1 1 1 1 0
    6 2
    0 1 0 0 0 1
    0 1 1 0 0 1
    0 1 1 0 1 0
    7 2
    0 1 0 0 1 0 1
                  j
    i = 6
    loc = 5
    trans = 2
*/
int pylons(int k, vector<int> arr)
{
    int n = arr.size();
    int i = 0, j = 0, loc = 0, trans = 0;
    while (i < n)
    {
        trans++;
        j = i + k - 1;
        if (j >= n)
        {
            j = n - 1;
        }
        while (loc <= j && arr[j] == 0)
        {
            j--;
        }
        if (j < i)
        {
            return -1;
        }
        else
        {
            loc = j;
            j += k;
            i = j;
        }
    }
    return trans;
}

#define DEBUG_MODE

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
