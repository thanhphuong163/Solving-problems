// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 
// Submit: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void read_array(string line, vector<int> &nums) {
    stringstream ss(line);
    int num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string line;
        getline(cin, line);
        vector<int> nums;
        read_array(line, nums);
        /* your code */
    }
    return 0;
}
