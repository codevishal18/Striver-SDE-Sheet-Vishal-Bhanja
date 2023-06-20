#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

void solve(TreeNode<int> *root,int &ans,int X)
{
    if(root==NULL)
    {
        return;
    }

    if(root->val>X)
    {
        solve(root->left,ans,X);
    }
    else if(root->val<X)
    {
        ans = root->val;
        solve(root->right,ans,X);
    }
    else
    {
        ans = root->val;
        return;
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans = -1;
    solve(root,ans,X);
    return ans;
}