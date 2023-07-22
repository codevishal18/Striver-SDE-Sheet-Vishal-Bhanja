/*Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.*/

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


class BSTiterator
{
    public:
    stack<TreeNode<int> *> st;

    void pinorder(TreeNode<int> *root)
    {
        while(root!=NULL)
        {
            st.push(root);
            root = root->left;
        }
    }

    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pinorder(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int> *z = st.top();
        st.pop();
        pinorder(z->right);
        return z->data;
    }

    bool hasNext()
    {
        // write your code here
        if(st.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/