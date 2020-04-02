// Author: Nguyen Thanh Phuong
// Email: thanhphuong.its@gmail.com
// Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Submit:

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

void print_list(ListNode* head) {
    ListNode *p = head;
    while (p)
    {
        if (p->next)
            cout << p->val << "->";
        else
            cout << p->val;
        p = p->next;
    }
    cout << endl;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *p1 = head;
    ListNode *p2 = head;
    if (!head || !n) return head;

    int size = 0;
    while (p1) {
        size++;
        p1 = p1->next;
    }
    p1 = head;
    n = size - n;
    if (n > 0) {
        for (int i = 0; i < n; ++i)
        {
            p2 = p2->next;
        }
        for (int i = 0; i < n - 1; ++i)
        {
            p1 = p1->next;
        }
        p1->next = p2->next;
        delete p2;
    }
    else {
        head = head->next;
        delete p1;
    }

    return head;
}

int main(int argc, char const *argv[]) {
    int n_testcase;
    scanf("%d\n", &n_testcase);
    while (n_testcase--) {
        int n;
        scanf("%d\n", &n);
        string line;
        getline(cin, line);
        stringstream ss(line);
        int i;
        ListNode *head = NULL;
        while (ss >> i) {
            ListNode *node = new ListNode(i);
            node->next = head;
            head = node;
        }
        ListNode *p = removeNthFromEnd(head, n);
        print_list(p);
        ListNode *t = p;
        while (p) {
            delete t;
            t = p->next;
            p = p->next;
        }
    }
    return 0;
}
