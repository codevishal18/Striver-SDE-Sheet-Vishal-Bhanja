#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void solve(TreeNode<int> *root,int &ans,int k,int &index)
{
    if(root==NULL)
    {
        return;
    }
    solve(root->right,ans,k,index);
    index++;
    if(k==index)
    {
        ans = root->data;
        return;
    }
    solve(root->left,ans,k,index);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int ans = -1;
    int index = 0;
    solve(root,ans,k,index);
    return ans;
}
