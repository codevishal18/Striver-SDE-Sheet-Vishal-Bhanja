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
    };

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    map<int,int> m;
    queue<pair<BinaryTreeNode<int> *,int>> q;
    q.push({root,0});

    while(q.empty()==false)
    {
        BinaryTreeNode<int> *curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        m[dist] = curr->data;

        if(curr->left!=NULL)
        {
            q.push({curr->left,dist-1});
        }

        if(curr->right!=NULL)
        {
            q.push({curr->right,dist+1});
        }
    }

    for(auto x:m)
    {
        ans.push_back(x.second);
    }

    return ans;
}
