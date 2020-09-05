// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 

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

#define DEBUG_MODE 0
#if DEBUG_MODE == 1
    #define imie(...) "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "]"
    #define LOG(variable) cout << imie(variable) << endl
#else
    #define LOG(msg)
#endif

using namespace std;

// Read input
void readArray(string line, vi &nums) {
    stringstream ss(line);
    int num;
    while(ss >> num) {
        nums.push_back(num);
    }
}

// Print array
void printArray(vi &nums) {
    for(int num : nums) {
        cout << num << " ";
    }
    puts("");
}

/*
compare c-(b-i) == a-i for i from 0 to a
*/
void checkMolecules(int a, int b, int c) {
    int min_ = min(a,min(b,c));
    for (int i = 0; i <= min; i++) {
        if (c-(b-i) == a-i) {
            cout << i << " " << b-i << " " << a-i << endl;
            return;
        }
    }
    cout << "Impossible\n";
}

int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    /* Put your debugging code here */
#else
    int a,b,c;
    while (cin >> a >> b >> c)
    {
        checkMolecules(a,b,c);
    }
#endif
    return 0;
}
