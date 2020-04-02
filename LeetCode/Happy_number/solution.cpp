// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/happy-number/
// Submit:

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

bool isExisted(int n, vector<int>& vi) {
    if (!vi.empty()) {
        for (int i = 0; i < vi.size(); ++i)
        {
            if (n == vi[i])
                return true;
        }
    }
    return false;
}

int sum_squares(int n) {
    vector<int> digits;
    while (floor(n / 10)) {
        digits.push_back(n%10);
        n = floor(n / 10);
    }
    digits.push_back(n);
    int sum = 0;
    for (const int i : digits) {
        sum += i*i;
    }
    return sum;
}

bool isHappy_vector(int n) {
    vector<int> stack;
    int s = sum_squares(n);
    while (s != 1) {
        stack.push_back(s);
        s = sum_squares(s);
        if (isExisted(s, stack))
            return false;
    }
    return true;
}

bool isHappy_map(int n) {
    map<int, int> cycle;
    while (n != 1)
    {
        int sum_squares = 0;
        while (n)
        {
            int digit = n % 10;
            sum_squares += digit * digit;
            n /= 10;
        }
        n = sum_squares;
        if (cycle[sum_squares] == 1)
            return false;
        else
            cycle[sum_squares] = 1;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    int n_testcase;
    scanf("%d\n", &n_testcase);
    while (n_testcase > 0) {
        int n;
        cin >> n;
        cout << "Is " << n << " a happy number? " << isHappy_vector(n) << endl;
        cout << "Is " << n << " a happy number? " << isHappy_map(n) << endl;
        n_testcase--;
    }
    return 0;
}
