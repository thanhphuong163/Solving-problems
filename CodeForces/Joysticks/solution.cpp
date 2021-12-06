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
void solution(int a, int b) {
    /* Your code here */
    int count = 0;
    while (a > 0 && b > 0) {
        if (a <= 1 && b <= 1) break;
        if (a > b) {
            b++;
            a = a - 2;
        }
        else {
            a++;
            b = b - 2;
        }
        count++;
    }
    cout << count << endl;
}

int main(int argc, char const *argv[])
{
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    int a, b;
    while (cin >> a >> b)
    {
        cin.ignore();
        solution(a, b);
    }
#endif
    return 0;
}
