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

void postorder(TreeNode *root,vector<int>& v)
{
    if(root!=NULL)
    {
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->data);
    }
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> v;
    postorder(root,v);
    return v;
}