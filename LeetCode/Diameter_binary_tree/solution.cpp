// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem:
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

/* Write your solution here */

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    int max_diameter = 0;
    int get_height(TreeNode *node)
    {
        if (node == NULL)
        {
            max_diameter = max(0, max_diameter);
            return 0;
        }
        else
        {
            int left_height = get_height(node->left);
            int right_height = get_height(node->right);
            max_diameter = max(max_diameter, left_height + right_height);
            return max(1 + left_height, 1 + right_height);
        }
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int tree_height = get_height(root);
        return max_diameter;
    }
};

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums;
        read_array(line, nums);
        /* your code here */
    }
    return 0;
}
