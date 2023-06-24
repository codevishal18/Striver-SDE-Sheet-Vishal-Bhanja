#include<bits/stdc++.h>
using namespace std;

   template <typename T>
   class TreeNode
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
TreeNode<int>* solve(vector<int> &inOrder,vector<int> &postOrder,int is,int ie,int ps,int pe,unordered_map<int,int> &mp)
{
     if(ps>pe || is>ie)
     {
          return NULL;
     }

     TreeNode<int>* root = new TreeNode<int>(postOrder[pe]);
     int ind = mp[root->data];
     int n = ind-is;

     root->left = solve(inOrder,postOrder,is,ind-1,ps,ps+n-1,mp);
     root->right = solve(inOrder,postOrder,ind+1,ie,ps+n,pe-1,mp);
     return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     unordered_map<int,int> mp;
     int n = postOrder.size();
     for(int i=0;i<inOrder.size();i++)
     {
          mp[inOrder[i]]=i;
     }

     return solve(inOrder,postOrder,0,n-1,0,n-1,mp);
}
