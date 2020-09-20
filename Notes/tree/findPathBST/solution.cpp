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

#define DEBUG_MODE 0

#if DEBUG_MODE == 1
    #define imie(...) "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "]"
    #define LOG(variable) cout << imie(variable) << endl
#else
    #define LOG(msg)
#endif

using namespace std;

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

/*
    - First build a binary search tree
    - Find the path in two cases:
        - Different subtrees of root node
        - Same subtrees of root node
*/
struct node {
    int val;
    node* left = NULL;
    node* right = NULL;
    node(int val) {
        val = val;
    }
    node(int val, node* left, node* right) {
        val = val;
        left = left;
        right = right;
    }
};

node* addNode(vi &nums, int i) {
    if (i < nums.size() && nums[i] != 0) {
        node* p = new node(val);
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

void findLeft(node* p, int left, vi &ans) {
    if (p->val < left) {
        findLeft(p->right, left, ans);
    }
    else if (p->val > left) {
        findLeft(p->left, left, ans);
    }
    ans.push_back(p->val);
}

void findRight(node* p, int right, vi &ans) {
    ans.push_back(p->val);
    if (p->val < right) {
        findLeft(p->right, right, ans);
    }
    else if (p->val > right) {
        findLeft(p->left, right, ans);
    }
}

vi findPathBST(node* root, int left, int right) {
    vi ans;
    if (root) {
        while(root->val < left) root = root->right;
        while(root->val > right) root = root->left;
        findLeft(root, left, ans);
        findRight(root->right, right, ans);
    }
    return ans;
}


int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    vi nums {6,3,9,1,4,7,10,0,8};
    node* root = buildBST(nums);
    printArray(findPathBST(root,4,8));
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
