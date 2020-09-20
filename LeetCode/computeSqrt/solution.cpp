// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/sqrtx/

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define ulli unsigned long long int
#define lli long long int
#define vulli vector<ulli>
#define vi vector<int>
#define vvi vector<vi>

#define DEBUG_MODE 1
#if DEBUG_MODE == 1
    #define imie(...) "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "]"
    #define LOG(variable) cout << imie(variable) << endl
#else
    #define LOG(msg)
#endif

using namespace std;

// Read input
void readArray(string line, vector<ulli> &nums) {
    stringstream ss(line);
    ulli num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}
void readArray(string line, vi &nums) {
    stringstream ss(line);
    int num;
    while(ss >> num) {
        nums.push_back(num);
    }
}

// Print array
void printArray(vulli &nums) {
    for (ulli num : nums)
    {
        cout << num << " ";
    }
    puts("");
}
void printArray(vi &nums) {
    for(int num : nums) {
        cout << num << " ";
    }
    puts("");
}

/*
    mySqrt(n, precision)
        l = 0
        r = n
        mid = n/2
        while abs(mid * mid - n) > precision:
            if mid * mid > n then r = mid
            else l = mid
            mid = l + (r - l) /2
*/
float mySqrt(float n, float precision) {
    float l = 0, r = n;
    float mid = n/2;
    int count = 0;
    while (abs(mid * mid - n) > precision) {
        if (mid * mid > n) r = mid;
        else l = mid;
        mid = l + (r - l) / 2;
        count++;
    }
    cout << count << endl;
    return mid;
}

int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    float n = 8;
    float precision = 1e-3;
    cout << mySqrt(n, precision) << endl;
#else
    string line;
    while (getline(cin, line))
    {
        vi nums;
        readArray(line, nums);
        /* your code here */
    }
#endif
    return 0;
}
