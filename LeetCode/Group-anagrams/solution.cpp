// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/group-anagrams/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#define vs vector<string>

using namespace std;

void read_array(string line, vector<int> &nums)
{
    stringstream ss(line);
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

void print_array(vector<vs> str_arr)
{
    for (vs vec_str : str_arr)
    {
        for (string s : vec_str)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}

vector<vs> groupAnagrams(vs &strs)
{
    unordered_map<string, vs> map;
    vector<vs> ans;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        map[s].push_back(strs[i]);
    }
    unordered_map<string, vs>::iterator it;
    for (it = map.begin(); it != map.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string line;
    vector<string> strs;
    while (getline(cin, line))
    {
        string line;
        strs.push_back(line);
    }
    for (string s : strs)
    {
        cout << s << endl;
    }
    // vector<vs> ans = groupAnagrams(strs);
    // print_array(ans);
    return 0;
}
