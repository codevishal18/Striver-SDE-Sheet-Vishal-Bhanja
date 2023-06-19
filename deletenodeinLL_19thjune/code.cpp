#include <bits/stdc++.h>
using namespace std;

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    node->data = node->next->data;
    LinkedListNode<int> *curr = node->next;
    node->next = node->next->next;
    delete curr;
}