#include<bits/stdc++.h>   
using namespace std;

   class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };

Node* merge2lists(Node* a,Node* b)
{
	Node *temp = new Node(0);
	Node *curr = temp;

	while(a!=NULL && b!=NULL)
	{
		if(a->data<b->data)
		{
			curr->child = a;
			curr=curr->child;
			a=a->child;
		}
		else
		{
			curr->child=b;
			curr=curr->child;
			b=b->child;
		}
	}

	if(a)
	{
		curr->child=a;
	}
	else
	{
		curr->child=b;
	}

	return temp->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL)
	{
		return head;
	}

	Node *h1 = flattenLinkedList(head->next);
	head->next = NULL;
	Node *nh = merge2lists(head, h1);
	return nh;
}
