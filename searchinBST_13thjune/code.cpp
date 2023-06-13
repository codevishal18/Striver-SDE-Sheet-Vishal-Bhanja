#include <bits/stdc++.h>
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
    };

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> *curr = root;
    while(curr!=NULL)
    {
        if(curr->data==x)
        {
            return true;
        }
        else if(curr->data>x)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }

    return false;
}