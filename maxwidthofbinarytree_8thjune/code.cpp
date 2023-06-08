#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
    public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) 
       return 0;
    queue<TreeNode<int>*>q;
    int ans=INT_MIN;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        ans=max(ans,s);
        while(s--){
            auto it=q.front();
            q.pop();
            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
        }
    }
    return ans;
}