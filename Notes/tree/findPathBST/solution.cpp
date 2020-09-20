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

void getPath(node* p, int x, vi &ans) {
    if (p) {
        ans.push_back(p->val);
        if (p->val > x) getPath(p->left, x, ans);
        if (p->val < x) getPath(p->right, x, ans);
    }
}

vi getPathBST(node* root, int L, int R) {
    vi path1;
    vi path2;
    getPath(root, L, path1);
    getPath(root, R, path2);
    int intersection = -1;
    int i = 0, j = 0;
    while(i < path1.size() || j < path2.size()) {
        if (j == i && path1[i] == path2[j]) {
            i++;
            j++;
        }
        else {
            intersection = j-1;
            break;
        }
    }
    vi ans;
    for (int i = path1.size()-1; i > intersection ; i--)
    {
        ans.push_back(path1[i]);
    }
    for (int i = intersection; i < path2.size(); i++) {
        ans.push_back(path2[i]);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
#if DEBUG_MODE == 1
    vi nums = {6,3,9,1,4,7,10,0,0,0,0,0,8};
    node* root = buildBST(nums);
    cout << root->right->left->right->val << endl;
    vi path = getPathBST(root, 4, 8);
    printArray(path);
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
