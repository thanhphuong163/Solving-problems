// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 
// Submit: 

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define min(a,b) (a <= b ? a : b)
#define max(a,b) (a > b ? a : b)

using namespace std;

int cal_area(vector<int> &height, int i, int j)
{
    int area = (j - i) * min(height[i], height[j]);
    return area;
}

int maxArea_bruteforce(vector<int>& height) {
    int max_area = 0;
    for (int i = 0; i < height.size(); ++i)
    {
        for (int j = i + 1; j < height.size(); ++j)
        {
            int area = cal_area(height, i, j);
            max_area = max(area, max_area);
        }
    }
    return max_area;
}

int maxArea(vector<int>& height) {
    int max_area = 0;
    int l = 0;
    int r = height.size()-1;
    while ( l < r) {
        max_area = max(cal_area(height, l, r), max_area);
        if (height[l] < height[r]) 
            l++;
        else
            r--;
    }

    return max_area;
}

int main(int argc, char const *argv[]) {
    int n_testcase;
    scanf("%d\n", &n_testcase);
    int i = 1;
    while (i <= n_testcase) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int h;
        vector<int> heights;
        while (ss >> h) {
            heights.push_back(h);
        }

        int ans = maxArea_bruteforce(heights);
        int my_ans = maxArea(heights);
        string status = ans == my_ans ? "Success" : "Fail";
        printf("Testcase %d (output: %d, expected: %d) : %s\n", i++, my_ans, ans, status.c_str());
    }
    return 0;
}
