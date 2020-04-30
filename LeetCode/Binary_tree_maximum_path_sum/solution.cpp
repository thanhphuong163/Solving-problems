// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
Write your solution here
*/
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

int helper(TreeNode *node, int &maxSum)
{
    if (node == NULL)
        return 0;
    int left = helper(node->left, maxSum);
    int right = helper(node->right, maxSum);
    int leftOrRightOrNode = max(node->val, node->val + max(left, right));
    maxSum = max(maxSum, max(node->val + left + right, leftOrRightOrNode));
    return leftOrRightOrNode;
}

int maxPathSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    helper(root, maxSum);
    return maxSum;
}

// #define DEBUG_MODE
int main(int argc, char const *argv[])
{
#ifdef DEBUG_MODE
    /* Put your debugging code here */
#else
    string line;
    while (getline(cin, line))
    {
        vector<ulli> nums;
        read_array(line, nums);
        print_array(nums);
    }
#endif
    return 0;
}
