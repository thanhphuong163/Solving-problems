// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem:
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define vc vector<char>
#define vvc vector<vc>

using namespace std;

// Read input
void read_array(string line, vector<char> &nums)
{
    stringstream ss(line);
    char c;
    while (ss >> c)
    {
        nums.push_back(c);
    }
}

// Print out input
void print_array(vector<char> &nums)
{
    for (char i : nums)
    {
        cout << i << " ";
    }
    puts("");
}

/*
- start at a '1' in the grid
- make it '0' and traverse all it adjacent '1' in the same way.
- continue the above step until you traversed all '1's in the grid.
*/
void turnZeros_DFS(vvc &grid, int x, int y)
{
    grid[x][y] = '0';
    if (x - 1 >= 0 && grid[x - 1][y] == '1')
        turnZeros_DFS(grid, x - 1, y);
    if (y - 1 >= 0 && grid[x][y - 1] == '1')
        turnZeros_DFS(grid, x, y - 1);
    if (x + 1 < grid.size() && grid[x + 1][y] == '1')
        turnZeros_DFS(grid, x + 1, y);
    if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
        turnZeros_DFS(grid, x, y + 1);
}

int numIslands(vvc &grid)
{
    int rows = grid.size();
    if (rows == 0)
        return 0;
    int cols = grid[0].size();
    if (cols == 0)
        return 0;
    int islandCount = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            {
                islandCount++;
                turnZeros_DFS(grid, i, j);
            }
        }
    }
    return islandCount;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    vvc grid;
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'1', '1', '0', '0', '0'});
    grid.push_back({'0', '0', '1', '0', '0'});
    grid.push_back({'0', '0', '0', '1', '1'});
    cout << numIslands(grid) << endl;

#else
    int rows, cols;
    while (cin >> rows >> cols)
    {
        cin.ignore();
        string line;
        vvc grid;
        while (rows--)
        {
            getline(cin, line);
            vc row;
            read_array(line, row);
            grid.push_back(row);
            // print_array(row);
        }
        cout << numIslands(grid) << endl;
    }
#endif
    return 0;
}
