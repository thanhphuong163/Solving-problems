// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/last-stone-weight/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

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
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq;
    
    for (int stone : stones)
    {
        pq.push(stone);
    }
    
    while (pq.size() >= 2)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        if (first != second)
        {
            pq.push(first - second);
        }
    }
    if (pq.size() == 1)
        return pq.top();
    else
        return 0;
}

int main(int argc, char const *argv[]) {
    string line;
    while (getline(cin, line))
    {
        vector<int> nums;
        read_array(line, nums);
        cout << lastStoneWeight(nums) << endl;
    }
    return 0;
}
