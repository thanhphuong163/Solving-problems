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
int min(int a, int b) {
    return a < b ? a : b;
}

int solution(vi nums) {
    /* Your code here */
    int sum = 0;
    for(int i : nums) {
        if (i > 0)
            sum += i;
    }
    int max_odd = nums[0];
    int min_odd = nums[0];
    for (int i : nums) {
        if (i%2 == 1) {
            if (i < 0 && i > max_odd) max_odd = i;
            if (i > 0 && i < min_odd) min_odd = i;
        }
    }
    if (sum%2 == 1) return sum;
    else return sum - min(min_odd, max_odd);
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
        int s = solution(nums);
        cout << s << endl;
    }
#endif
    return 0;
}
