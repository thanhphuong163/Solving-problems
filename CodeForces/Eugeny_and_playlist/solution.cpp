// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 
// Submit: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define vi vector<int>

using namespace std;

// Read input
void read_array(string line, vector<int> &nums) {
    stringstream ss(line);
    int num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}

// Print out input
void print_array(vector<int> &nums) {
    for (int i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    pref:   0 2 4 5 9
    moment: 1 2 3 4 5 6 7 8 9
*/
void getSongAtMoment(vi &c, vi &t, vi &moments) {
    vi pref(c.size()+1, 0);
    for (int i = 1; i <= c.size(); i++) {
        pref[i] = pref[i-1] + c[i-1] * t[i-1];
    }
    int j = 0;
    int i = 0;
    while (i < moments.size()) {
        if (moments[i] <= pref[j] || j >= pref.size()) {
            cout << j << endl;
            i++;
        }
        else {
            j++;
        }
    }
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int n, m;
    while (cin >> n >> m)
    {
        cin.ignore();
        vector<int> c,t;
        while (n--) {
            int c_, t_;
            cin >> c_ >> t_;
            cin.ignore();
            c.push_back(c_);
            t.push_back(t_);
        }
        string line;
        getline(cin, line);
        vector<int> moments;
        read_array(line, moments);
        getSongAtMoment(c,t,moments);
    }
#endif
    return 0;
}
