#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };
    
void solve(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2,bool &ans)
{
    if(root1==NULL and root2==NULL)
    {
        return;
    }

    if(root1==NULL || root2==NULL || root1->data!=root2->data)
    {
        ans = false;
        return;
    }

    solve(root1->left,root2->right,ans);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.
    bool ans = true;
    solve(root,root,ans);
    return ans;    
}