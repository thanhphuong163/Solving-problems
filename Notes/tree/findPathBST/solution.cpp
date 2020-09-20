// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: Find the path between two nodes in a binary search tree

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define ulli unsigned long long int
#define lli long long int
#define vulli vector<ulli>
#define vi vector<int>
#define vvi vector<vi>

#define DEBUG_MODE 1

#if DEBUG_MODE == 1
    #define imie(...) "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "]"
    #define LOG(variable) cout << imie(variable) << endl
#else
    #define LOG(msg)
#endif

using namespace std;

struct node
{
    int val;
    node *left = NULL;
    node *right = NULL;
};

// Read input
void readArray(string line, vector<ulli> &nums) {
    stringstream ss(line);
    ulli num;
    while (ss >> num) {
    	nums.push_back(num);
    }
}
void readArray(string line, vi &nums) {
    stringstream ss(line);
    int num;
    while(ss >> num) {
        nums.push_back(num);
    }
}

// Print array
void printArray(vulli &nums) {
    for (ulli num : nums)
    {
        cout << num << " ";
    }
    puts("");
}
void printArray(vi &nums) {
    for(int num : nums) {
        cout << num << " ";
    }
    puts("");
}
void printBST(node* p) {
    if (p) {
        cout << p->val << " ";
        printBST(p->left);
        printBST(p->right);
    }
    else {
        cout << "NULL ";
    }
}

/*
    - First build a binary search tree
    - Find the path in two cases:
        - Different subtrees of root node
        - Same subtrees of root node
*/

node* addNode(vi &nums, int i) {
    if (i < nums.size() && nums[i] != 0) {
        node* p = new node();
        p->val = nums[i];
        p->left = addNode(nums, 2*i + 1);
        p->right = addNode(nums, 2*i + 2);
        return p;
    }
    return NULL;
}

node* buildBST(vi &nums) {
    int n = nums.size();
    if (n == 0) return NULL;
    node* root = addNode(nums, 0);
    return root;
}



int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    vi nums = {6,3,9,1,4,7,10,0,8};
    node* root = buildBST(nums);
    cout >> root->left->val >> endl;;
#else
    string line;
    while (getline(cin, line))
    {
        vi nums;
        readArray(line, nums);
        /* your code here */
    }
#endif
    return 0;
}
