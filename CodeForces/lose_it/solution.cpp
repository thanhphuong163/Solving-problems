// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define ulli unsigned long long int
#define lli long long int
#define vulli vector<ulli>
#define vi vector<int>
#define vvi vector<vi>

#define DEBUG_MODE 0
#if DEBUG_MODE == 1
#define imie(...) "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "]"
#define LOG(variable) cout << imie(variable) << endl
#else
#define LOG(msg)
#endif

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums)
{
    stringstream ss(line);
    ulli num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}
void read_array(string line, vi &nums)
{
    stringstream ss(line);
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

// Print array
void print_array(vulli &nums)
{
    for (ulli num : nums)
    {
        cout << num << " ";
    }
    puts("");
}
void print_array(vi &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    puts("");
}

/*
Write your solution here
*/
void solution(vi &nums, int n) {
    vector<int> p({4,8,15,16,23,42});
    for (int i=0; i < n; i++) {
        nums[i] = lower_bound(p.begin(), p.end(), nums[i]) - p.begin();
    }
    vi seq(6);
    for (int i=0; i < n; i++) {
        if (nums[i] == 0) {
            ++seq[0];
        }
        else {
            if (seq[nums[i] - 1] > 0) {
                --seq[nums[i] - 1];
                ++seq[nums[i]];
            }
        }
    }
    cout << n - seq[5] * 6 << endl;
}

int main(int argc, char const *argv[])
{
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    int n;
    string line;
    while (cin >> n)
    {
        cin.ignore();
        getline(cin, line);
        vi nums;
        read_array(line, nums);
        solution(nums, n);
    }
#endif
    return 0;
}
