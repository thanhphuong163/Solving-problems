// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/backspace-string-compare/
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

/* Write your solution here */
bool backspaceCompare(string S, string T)
{
    int k = 0;
    int l = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '#')
        {
            k--;
            k = max(k, 0);
        }
        else
        {
            S[k] = S[i];
            k++;
        }
    }
    for (int i = 0; i < T.length(); i++)
    {
        if (T[i] == '#')
        {
            l--;
            l = max(l, 0);
        }
        else
        {
            T[l] = T[i];
            l++;
        }
    }
    if (k != l)
        return false;
    else
    {
        for (int i = 0; i < k; i++)
        {
            if (S[i] != T[i])
                return false;
        }
        return true;
    }
}

int main(int argc, char const *argv[])
{
    string S;
    while (getline(cin, S))
    {
        string T;
        getline(cin, T);
        if (backspaceCompare(S, T))
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
