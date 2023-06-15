#include<bits/stdc++.h>
using namespace std;

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast)
        {
            fast=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }

            return slow;
        }
    }

    return NULL;
}