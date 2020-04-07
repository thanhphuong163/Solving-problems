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
    cout << seq << endl;
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
    cout << "done" << endl;
    return 0;
}
