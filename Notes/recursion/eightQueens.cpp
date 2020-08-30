#include <iostream>
#include <vector>

#define pii pair<int,int>
#define vpii vector<pii>

using namespace std;

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void putOnBoard(int row, vector<int>& board) {
    int n = board.size();
    if (row == n) {
        printArray(board);
    }
    else {
        vector<int> feasible(n, 1);
        for (int i = 0; i < row; ++i) {
            feasible[board[i]] = 0;
            int a = board[i] - (row-i);
            int b = board[i] + (row-i);
            if (a >= 0) feasible[a] = 0;
            if (b < n) feasible[b] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (feasible[i]) {
                board[row] = i;
                putOnBoard(row+1, board);
            }
        }
    }
}

void solveEightQueens(int n) {
    vector<int> board(n, -1);
    putOnBoard(0, board);
}

int main(int argc, char const *argv[])
{
    int n = 4;
    cout << "Enter an integer: ";
    cin >> n;
    solveEightQueens(n);
    return 0;
}
