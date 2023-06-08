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

void solve(BinaryTreeNode<int> *root,vector<vector<int>> &v)
{
    if(root!=NULL)
    {
        v[1].push_back(root->data);
        solve(root->left,v);
        v[0].push_back(root->data);
        solve(root->right,v);
        v[2].push_back(root->data);
    }
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> v(3);
    solve(root,v);
    return v;
}