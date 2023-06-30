#include <bits/stdc++.h> 
using namespace std;

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

void inorder(BinaryTreeNode<int>* root,vector<int>& ans)
{
    if(root!=NULL)
    {
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    vector<int> ans;
    inorder(root,ans);
    pair<int,int> p;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]==key)
        {
            p.first = (i==0)?-1:ans[i-1];
            p.second = (i==ans.size()-1)?-1:ans[i+1];
        }
    }

    return p;
}
