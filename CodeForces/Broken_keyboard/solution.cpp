//https://codeforces.com/problemset/problem/1251/A
// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: A Broken Keyboard
// Submit: solved

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void read_input(string line, string &s)
{
    stringstream ss(line);
    ss >> s;
}

void get_functional_keys(string &seq)
{
    string ans;
    int len = seq.length();
    set<char> s;
    if (len > 1)
    {
        if (seq[0] != seq[1])
        {
            ans += seq[0];
        }
        for (int i = 1; i < len - 1; i++)
        {
            if (seq[i] != seq[i - 1] && seq[i] != seq[i + 1])
                s.insert(seq[i]);
        }
        if (seq[len - 1] != seq[len - 2])
        {
            ans += seq[len - 1];
        }
    }
    else
    {
        ans = seq;
    }
    for (char c : s)
    {
        ans += c;
    }
    cout << ans << endl;
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
