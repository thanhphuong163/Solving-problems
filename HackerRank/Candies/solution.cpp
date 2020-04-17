// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://www.hackerrank.com/challenges/candies/problem
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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

// Print out input
void print_array(vector<int> &nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
    - Go through the line of students:
        - if the i^th student's score greater than the previous student's one, then give them more candies.
        - else check if the previous student only has one candy, give them one more, and the current one, one candy.
*/
long candies(int n, vector<int> arr)
{
    if (n == 1) return 1;
    int numCandies = 1;
    int prevCandies = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i-1] < arr[i]) {
            prevCandies += 1;
            numCandies += prevCandies;
        }
        else {
            if (prevCandies == 1)
                numCandies += prevCandies + 1;
            else {
                prevCandies = 1;
                numCandies += prevCandies;
            }
        }
    }
    return numCandies;
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            int arr_item;
            cin >> arr_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            arr[i] = arr_item;
        }

        long result = candies(n, arr);

        cout << result << "\n";
    }
    
    return 0;
}
