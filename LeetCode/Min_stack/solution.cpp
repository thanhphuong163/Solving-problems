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
class MinStack
{
public:
    /** initialize your data structure here. */
    struct Node
    {
        int data;
        int min;
        Node *next;
    };

    Node *head;

    MinStack()
    {
        this->head = NULL;
    }

    void push(int x)
    {
        Node *node = new Node();
        node->data = x;
        if (!this->head)
        {
            node->min = x;
        }
        else
        {
            if (x < this->head->min)
            {
                node->min = x;
            }
            else
            {
                node->min = this->head->min;
            }
        }

        node->next = this->head;
        this->head = node;
    }

    void pop()
    {
        Node *node = this->head;
        this->head = node->next;
        delete node;
    }

    int top()
    {
        return this->head->data;
    }

    int getMin()
    {
        return this->head->min;
    }
};

int main(int argc, char const *argv[])
{
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.push(-4);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}
