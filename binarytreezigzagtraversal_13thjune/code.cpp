#include <bits/stdc++.h> 
using namespace std;

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> v1;
       if(root==NULL)
       {
           return v1;
       }
       queue<BinaryTreeNode<int>*> q;
       q.push(root);
       int k = 1;
       while(q.empty()==false)
       {
           int count = q.size();
           vector<int> v;
           for(int i=0;i<count;i++)
           {
               BinaryTreeNode<int> *curr = q.front();
               q.pop();
               
               v.push_back(curr->data);
               
               if(curr->left!=NULL)
               {
                   q.push(curr->left);
               }
               if(curr->right!=NULL)
               {
                   q.push(curr->right);
               }
               
           }
           if(k%2==0)
           {
                   reverse(v.begin(),v.end());
           }
           for(int i=0;i<v.size();i++)
           {
               v1.push_back(v[i]);
           }
           k++;
       }
       return v1;
}
