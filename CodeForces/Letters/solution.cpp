// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://codeforces.com/problemset/problem/978/C
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

// Two pointers solution with time complexity O(N),
// where N is the number of dorms.
void deliver_letter(vector<int> &n_room, vector<int> &letters)
{
    vector<int> cum_sum(n_room.size() + 1);
    cum_sum[0] = 0;
    for (int i = 1; i < cum_sum.size(); i++)
    {
        cum_sum[i] = cum_sum[i - 1] + n_room[i - 1];
    }
    int i = 0; // index on cum_sum
    int j = 0; // index on letters
    while (j < letters.size())
    {
        if (i < cum_sum.size()) {
            if (letters[j] <= cum_sum[i])
            {
                cout << i << " " << letters[j] - cum_sum[i - 1] << endl;
                j++;
            }
            else
                i++;
        }
        else {
            cout << i << " " << letters[j] - cum_sum[i - 1] << endl;
            j++;
        }
        
    }
}

/*
There is another solution using binary search.
We calculate cum_sum, then use binary search letter
on cum_sum. With this approach, the time complexity
will be O(NlogN), where n is number of dorms.
*/

int main(int argc, char const *argv[])
{
    int n_dorm;
    int n_letter;
    while (cin >> n_dorm >> n_letter)
    {
        cin.ignore();
        string line;
        // Get number of rooms of each dorm
        getline(cin, line);
        vector<int> n_room;
        read_array(line, n_room);
        // Get numbers on letters' envelops
        getline(cin, line);
        vector<int> letters;
        read_array(line, letters);
        // My solution
        deliver_letter(n_room, letters);
    }
    return 0;
}
