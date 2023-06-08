#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void preorder(TreeNode *root,vector<int>& v)
{
    if(root!=NULL)
    {
        v.push_back(root->data);
        preorder(root->left,v);
        preorder(root->right,v);
    }
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> v;
    preorder(root,v);
    return v;
}