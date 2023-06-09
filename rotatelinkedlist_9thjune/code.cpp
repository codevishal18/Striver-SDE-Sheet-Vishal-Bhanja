#include<bits/stdc++.h>
using namespace std;

 class Node {
 public:
      int data;
      Node *next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node *next) : data(x), next(next) {}
 };

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head==NULL || k==0)
     {
          return head;
     }

     int count = 1;
     Node *curr = head;
     while(curr->next!=NULL)
     {
          count++;
          curr=curr->next;
     }
     curr->next = head;

     k = k%count;
     int t = count-k;
     while(t--)
     {
          curr=curr->next;
     }

     Node *nh = curr->next;
     curr->next=NULL;
     return nh;
}