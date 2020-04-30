// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: 
// Submit: 

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define ulli unsigned long long int
#define ll long long
#define pil pair<ulli, int>

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
    Use Greedy
    Combine both arrays into one
    Sort in descending order
    
*/
ulli boardCutting(vector<ulli> cost_y, vector<ulli> cost_x)
{
    ulli c = 1e9+7;

    vector<pil> cuts;
    for (ulli x: cost_x) {
        cuts.push_back(make_pair(x, 0));
    }
    for (ulli y: cost_y) {
        cuts.push_back(make_pair(y, 1));
    }
    sort(cuts.begin(), cuts.end(), greater<pil>());
    ll x_pieces = 1;
    ll y_pieces = 1;
    ulli cost = 0;
    for (int i = 0; i < cuts.size(); i++) {
        if (cuts[i].second == 0) {
            cost += (cuts[i].first * y_pieces)%c;
            x_pieces++;
        }
        else {
            cost += (cuts[i].first * x_pieces)%c;
            y_pieces++;
        }
    }
    return cost%c;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[]) {
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    int q;
    cin >> q;
    cin.ignore();
    while (q--)
    {
        long long n, m;
        cin >> n >> m;
        cin.ignore();
        getline(cin,line);
        vector<ulli> cost_y;
        read_array(line, cost_y);
        getline(cin, line);
        vector<ulli> cost_x;
        read_array(line, cost_x);
        cout << boardCutting(cost_y, cost_x) << endl;
    }
#endif
    return 0;
}
