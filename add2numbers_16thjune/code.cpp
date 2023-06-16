#include<bits/stdc++.h>
using namespace std;

class Node {
public:
      int data;
      Node *next;
      Node() {
          this->data = 0;
          this->next = NULL;
      }
      Node(int data) {
          this->data = data;
          this->next = NULL;
      }
      Node (int data, Node *next) {
          this->data = data;
          this->next = next;
      }
 };

 
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    int carry = 0;
    Node *p1 = num1;
    Node *p2 = num2;
    Node *res = new Node(-1);
    Node *curr = res;

    while(p1!=NULL || p2!=NULL || carry!=0)
    {
        int sum = 0;
        if(p1!=NULL)
        {
            sum += p1->data;
            p1=p1->next;
        }

        if(p2!=NULL)
        {
            sum += p2->data;
            p2=p2->next;
        }

        sum += carry;
        carry = sum/10;

        Node *temp = new Node(sum%10);
        curr->next=temp;
        curr=curr->next;
    } 

    return res->next;
}
