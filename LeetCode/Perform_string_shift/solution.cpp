// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3299/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// #define DEBUG_MODE
#define vi vector<int>

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
    0: ans[i] = s[(i + pivot) % size]
    1: ans[i] = s[(i + size - pivot) % size]
*/
string stringShift(string s, vector<vector<int>> &shift)
{
    int len = s.length();
    for (int i = 0; i < shift.size(); i++)
    {
        string ans;
        int pivot = shift[i][0] ? len - shift[i][1] : shift[i][1];
        for (int j = 0; j < len; j++)
        {
            ans += s[(j + pivot) % len];
        }
        s = ans;
    }
    return s;
}

int main(int argc, char const *argv[])
{

#ifdef DEBUG_MODE
    string line = "abc";
    vector<vi> shift;
    shift.push_back({0, 1});
    shift.push_back({1, 2});
    cout << stringShift(line, shift) << endl;
#else // Test mode
    string line;
    while (getline(cin, line))
    {
        int n;
        cin >> n;
        vector<vi> shift;
        cin.ignore();
        while (n--)
        {
            int direction, amount;
            cin >> direction >> amount;
            cin.ignore();
            shift.push_back({direction, amount});
        }
        cout << stringShift(line, shift) << endl;
    }
#endif
    return 0;
}
