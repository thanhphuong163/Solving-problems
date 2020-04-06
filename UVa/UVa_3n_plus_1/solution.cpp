//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: The 3n + 1 problem
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_array(string line, vector<int> &nums)
{
    stringstream ss(line);
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        int i, j;
        cin >> i >> j;
        printf("%d %d %d\n", i, j, 100);
    }
    return 0;
}
