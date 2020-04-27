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
    Use extra array to accelerate time complexity
    - An n-size array to store the last placable positions
    7 2
    0 1 1 1 1 0 1
    extra array:
    -1 1 2 3 4 4 6
    ==> 3 at indices 1 4 6
*/
int pylons(int k, vector<int> arr)
{
    int n = arr.size();
    int last = -1, count = 0;
    int prv[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            last = i;
        prv[i] = last;
    }
    
    for (int i = 0; i < n;)
    {
        int take = prv[min(i + k - 1, n - 1)];
        if (take == -1 || take + k <= i)
            return -1;
        i = take + k;
        count++;
    }
    return count;
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
