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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    if(root==NULL)return {};

    vector<int> v;
    int first=0;
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            TreeNode<int> *temp=q.front();
            q.pop();

            if(first==0)
            {
                v.push_back(temp->data);
                first=1;
            }

            if(temp->left)q.push(temp->left);

            if(temp->right)q.push(temp->right);
        }
        first=0;
    }

    return v;
}