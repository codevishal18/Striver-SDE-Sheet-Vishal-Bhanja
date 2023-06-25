#include <bits/stdc++.h> 
using namespace std;

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

TreeNode<int>* solve(vector<int> &preOrder,int i,int j)
{
    if(i>j)
    {
        return NULL;
    }

    TreeNode<int>* root = new TreeNode<int>(preOrder[i]);
    int k = i+1;
    for(;k<=j;k++)
    {
        if(preOrder[k]>preOrder[i])
        {
            break;
        }
    }

    root->left = solve(preOrder,i+1,k-1);
    root->right = solve(preOrder,k,j);

    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    return solve(preOrder,0,preOrder.size()-1);
}