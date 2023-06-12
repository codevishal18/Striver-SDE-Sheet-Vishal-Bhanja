#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* d = new Node<int>(-1);
    Node<int>* p1 = first;
    Node<int>* p2 = second;
    Node<int>* curr = d;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data<=p2->data)
        {
            curr->next=p1;
            p1=p1->next;
        }
        else
        {
            curr->next=p2;
            p2=p2->next;
        }
        curr=curr->next;
    }

    if(p1==NULL)
    {
        curr->next=p2;
    }

    if(p2==NULL)
    {
        curr->next=p1;
    }

    return d->next;
}
