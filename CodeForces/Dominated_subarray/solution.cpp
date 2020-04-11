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

/* Write your solution here */

int main(int argc, char const *argv[]) {
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
        print_array(nums);
        /* your code here */
    }
    return 0;
}
