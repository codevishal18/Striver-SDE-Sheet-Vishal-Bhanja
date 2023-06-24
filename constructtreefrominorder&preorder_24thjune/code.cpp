#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

TreeNode<int>* solve(vector<int> &inorder,vector<int> &preorder,int is,int ie,int ps,int pe,unordered_map<int,int> &mp)
{
     if(ps>pe || is>ie)
     {
          return NULL;
     }

     TreeNode<int>* root = new TreeNode<int>(preorder[ps]);
     int ind = mp[root->data];
     int n = ind-is;

     root->left = solve(inorder,preorder,is,ind-1,ps+1,ps+n,mp);
     root->right = solve(inorder,preorder,ind+1,ie,ps+n+1,pe,mp);
     return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
     unordered_map<int,int> mp;
     int n = preorder.size();
     for(int i=0;i<inorder.size();i++)
     {
          mp[inorder[i]]=i;
     }

     return solve(inorder,preorder,0,n-1,0,n-1,mp);
}