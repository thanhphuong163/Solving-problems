// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: Rod Cutting
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
Write your solution here
*/
int rodCutting(const vector<int> prices, int length, int cost)
{
    vector<int> r(length + 1, 0);
    for (int j = 0; j <= length; j++)
    {
        int q = INT_MIN;
        for (int i = 0; i <= j; i++)
        {
            if (q < prices[i] + r[j - i] - cost)
            {
                q = prices[i] + r[j - i] - cost;
            }
        }
        r[j] = q;
    }
    return r[length];
}

#define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    vector<int> prices = { 0, 1, 5, 8, 10, 13, 17, 18, 22, 25, 30 };
    int length = 17;
    cout << rodCutting(prices, length, 0) << endl;
#else
    string line;
    vector<int> prices;
    getline(cin, line);
    read_array(line, prices);
    int length;
    while (cin >> length)
    {
        cin.ignore();
        cout << rodCutting(prices, length, 0) << endl;
    }
#endif
    return 0;
}
