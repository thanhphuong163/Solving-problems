// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/1251/A
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
    for (int i = 1; i < len - 1; i++)
    {
        if (seq[i] != seq[i - 1] && seq[i] != seq[i + 1])
            ans += seq[i];
    }
    if (seq[len - 1] != seq[len - 2])
    {
        ans += seq[len - 1];
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
