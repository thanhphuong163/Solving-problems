//https://codeforces.com/problemset/problem/1251/A
// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: A Broken Keyboard
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void read_input(string line, string &s)
{
    stringstream ss(line);
    ss >> s;
}

void get_functional_keys(string &seq)
{
    int base = int('a');
    int len = seq.length();
    vector<int> ans(26);
    for (int i = 0; i < 26; i++)
    {
        ans[i] = 0;
    }

    int l = 0, r = 0;
    while (r < len - 1)
    {
        if (seq[r] != seq[r + 1])
        {
            if ((r - l + 1) % 2 != 0)
            {
                ans[int(seq[l]) - base] = 1;
            }
            r++;
            l = r;
        }
        else
        {
            r++;
        }
    }
    if ((r - l + 1) % 2 != 0)
    {
        ans[int(seq[l]) - base] = 1;
    }

    // Print out solution
    for (int i = 0; i < 26; i++)
    {
        if (ans[i])
            cout << char(base + i);
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();
    string line;
    while (n--)
    {
        getline(cin, line);
        string s;
        read_input(line, s);
        get_functional_keys(s);
    }
    return 0;
}
