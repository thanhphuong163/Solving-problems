// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/3sum/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

#define vi vector<int>

using namespace std;

// Print result
void print_result(vector<vi> &result)
{
    if (!result.empty())
    {
        int height = result.size();
        int width = result.begin()->size();
        int indx = 1;
        cout << "[";
        for (vector<vi>::iterator it = result.begin(); it != result.end(); ++it)
        {
            cout << "[";
            for (int j = 0; j < width; ++j)
            {
                if (j < width - 1)
                    cout << it->at(j) << ", ";
                else
                    cout << it->at(j);
            }
            if (indx < height)
                cout << "], ";
            else
                cout << "]";
            indx++;
        }
        cout << "]" << endl;
    }
    else
    {
        cout << "[[]]" << endl;
    }
}

// Read input
void read_array(string line, vector<int> &nums)
{
    stringstream ss(line);
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

vector<vi> three_sum(vi &nums)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vi> ans;
    for (int i = 0; i < size; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) // ingore repeating number
            continue;
        if (nums[i] > 0)
            break;
        int l = i + 1;
        int r = size - 1;
        while (l < r)
        {
            if (nums[i] + nums[l] + nums[r] < 0)
                l++;
            else if (nums[i] + nums[l] + nums[r] > 0)
                r--;
            else
            {
                vi triplet;
                triplet.push_back(nums[i]);
                triplet.push_back(nums[l]);
                triplet.push_back(nums[r]);
                ans.push_back(triplet);
                do
                {
                    l++;
                } while (l < r && nums[l] == nums[l - 1]); // ignore repeating numbers
                do
                {
                    r--;
                } while (l < r && nums[r] == nums[r + 1]);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n_testcase;
    cin >> n_testcase;
    cin.ignore();
    while (n_testcase--)
    {
        string line;
        getline(cin, line);
        vi nums;
        read_array(line, nums);
        vector<vi> ans = three_sum(nums);
        print_result(ans);
    }

    return 0;
}

// -1 0 1 2 -1 4
// take out a number called x
// then we are left with the two sum problem with n-1 numbers
