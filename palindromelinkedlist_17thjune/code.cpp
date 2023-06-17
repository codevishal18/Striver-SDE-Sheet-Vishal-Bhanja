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


bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    LinkedListNode<int> *temp = slow;
    LinkedListNode<int> *prev = NULL;
    while(temp!=NULL)
    {
        LinkedListNode<int> *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    while(head!=slow)
    {
        if(prev->data!=head->data)
        {
            return false;
        }

        head=head->next;
        prev=prev->next;
    }

    return true;
}