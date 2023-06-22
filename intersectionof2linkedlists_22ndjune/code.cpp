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

Node* findIntersection(Node *head1, Node *head2)
{
    //Write your code here
    if(head1==NULL || head2==NULL )
           return NULL;
        
        Node* l1=head1;
        Node* l2=head2;
        while(l1!=l2)
        {
            l1= l1==NULL ? head2 : l1->next;
            l2= l2==NULL ? head1 : l2->next;
        }
        return l1;
}
