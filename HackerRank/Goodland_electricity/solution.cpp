// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/pylons/problem
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define ulli unsigned long long int

using namespace std;

// Read input
void read_array(string line, vector<ulli> &nums)
{
    stringstream ss(line);
    ulli num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
}

// Print out input
void print_array(vector<ulli> &nums)
{
    for (ulli i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    6 2
    0 1 1 1 1 0
    6 2
    0 1 0 0 0 1
    0 1 1 0 0 1
    0 1 1 0 1 0
    7 2
    0 1 0 0 1 0 1
                j
    i = 6
    loc = 5
    trans = 2
*/
int pylons(int k, vector<int> arr)
{
    int n = arr.size();
    int i = 0, j = 0, loc = 0, trans = 0;
    while (i < n) {
        trans++;
        j = i + k - 1;
        if (j >= n) {
            j = n-1;
        }
        while (loc <= j && arr[j] == 0) {
            j--;
        }
        if (j < loc) {
            return -1;
        }
        else {
            loc = j;
            j += k;
            i = j;
        }
    }
    return trans;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string nk_temp;

    while (getline(cin, nk_temp))
    {
        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = pylons(k, arr);

        cout << result << "\n";
    }

#endif
    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
