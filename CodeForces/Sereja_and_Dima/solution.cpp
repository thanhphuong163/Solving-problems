//https://codeforces.com/problemset/problem/381/A
// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: Sereja and Dima
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> play_game(vector<int> &cards)
{
    int sereja = 0;
    int dima = 0;
    int l = 0;
    int r = cards.size() - 1;
    bool is_sereja_turn = true;
    while (l <= r)
    {
        if (is_sereja_turn)
        {
            if (cards[l] > cards[r])
            {
                sereja += cards[l];
                l++;
            }
            else
            {
                sereja += cards[r];
                r--;
            }
            is_sereja_turn = false;
        }
        else
        {
            if (cards[l] > cards[r])
            {
                dima += cards[l];
                l++;
            }
            else
            {
                dima += cards[r];
                r--;
            }
            is_sereja_turn = true;
        }
    }
    vector<int> ans;
    ans.push_back(sereja);
    ans.push_back(dima);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n_testcase;
    scanf("%d\n", &n_testcase);
    vector<int> cards;
    while (n_testcase--)
    {
        int card;
        cin >> card;
        cards.push_back(card);
    }
    vector<int> ans = play_game(cards);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
