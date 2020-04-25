// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/angry-children/problem
// Submit: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define ulli unsigned long long int

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums) {
    stringstream ss(line);
    ulli num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}

// Print out input
void print_array(vector<ulli> &nums) {
    for (ulli i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    sort array
    two-pointer with k-size slide window
*/
int maxMin(int k, vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int unfairness = INT_MAX;
    for (int i = 0; i < n-k; i++) {
        unfairness = min(unfairness, arr[i+k-1] - arr[i]);
    }
    return unfairness;
}

// #define DEBUG_MODE

int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    int n;
    
    while (cin >> n) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            int arr_item;
            cin >> arr_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            arr[i] = arr_item;
        }

        int result = maxMin(k, arr);

        cout << result << "\n";
    }
    
#endif
    return 0;
}
