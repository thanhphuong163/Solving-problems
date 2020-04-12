// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/middle-of-the-linked-list/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

// Push new node into a linked list
void push(ListNode *&list, int num)
{
    ListNode *node = new ListNode(num);
    node->next = list;
    list = node;
}

// Clear linked list
void clear(ListNode *&list)
{
    ListNode *p = list;
    while (p)
    {
        list = p->next;
        delete p;
        p = list;
    }
}

/* Two pointers technique: fast-slow pointers */
ListNode *get_middle_node(ListNode *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    else if (head->next->next == NULL)
    {
        return head->next;
    }
    else
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next)
        {
            slow = slow->next;
            if (fast->next->next)
                fast = fast->next->next;
            else
                fast = fast->next;
        }
        return slow;
    }
}

int main(int argc, char const *argv[])
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums;
        read_array(line, nums);
        ListNode *list = NULL;
        for (int i : nums)
        {
            push(list, i);
        }
        ListNode *middle = get_middle_node(list);
        cout << middle->val << endl;
        clear(list);
    }
    return 0;
}
