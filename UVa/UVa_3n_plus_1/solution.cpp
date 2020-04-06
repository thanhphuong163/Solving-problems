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
        string line;
        getline(cin, line);
        vector<int> nums;
        read_array(line, nums);
        printf("%d %d %d\n", 3, 5, 2);
    }
    return 0;
}
