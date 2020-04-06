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

#define max(a, b) (a > b ? a : b)

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

int get_cycle_length(int num)
{
    int length = 1;
    while (num != 1)
    {
        if (num % 2 == 0)
            num /= 2;
        else
            num = 3 * num + 1;
        length++;
    }
    return length;
}

int max_cycle_length(int i, int j)
{
    int max_cylen = 0;
    if (i > j)
    {
        int tmp = j;
        j = i;
        i = tmp;
    }
    for (int num = i; num <= j; num++)
    {
        max_cylen = max(max_cylen, get_cycle_length(num));
    }
    return max_cylen;
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
        printf("%d %d %d\n", i, j, max_cycle_length(i, j));
    }
    return 0;
}
