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

vector<int>& read_array(string line) {
stringstream ss(line);
int num;
vector<int> nums;
while (ss >> num) {
nums.push_back(num);
}
return nums;
}

int main(int argc, char const *argv[]) {
int n_testcase;
scanf("%dn", &n_testcase);
while (n_testcase--) {
/* your code */
}
return 0;
