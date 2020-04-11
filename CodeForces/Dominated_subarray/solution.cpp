// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/contest/1257/problem/C
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#define vi vector<int>
#define min(a, b) (a < b ? a : b)

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
Using two pointers technique (head and tail of array)
- Since 1 <= a[i] <= n, we can use a (n+1)-size vector (default -1)
- Go through the array store position of value
- If position != -1 then compute distance between them.
- min_len = min(min_len, i - lst[a[i]] + 1)
- if min_len > size of array then return -1 else return min_len
*/

int min_len_dom_subarray(vector<int> &nums)
{
    int size = nums.size();
    int min_len = size + 5;
    vector<int> lst(size + 1, -1);
    for (int i = 0; i < size; i++)
    {
        if (lst[nums[i]] != -1)
        {
            min_len = min(min_len, i - lst[nums[i]] + 1);
        }
        lst[nums[i]] = i;
    }
    if (min_len > size)
        return -1;
    else
        return min_len;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        int size;
        scanf("%d\n", &size);
        string line;
        getline(cin, line);
        vector<int> nums;
        read_array(line, nums);
        //print_array(nums);
        cout << min_len_dom_subarray(nums) << endl;
    }
    return 0;
}
