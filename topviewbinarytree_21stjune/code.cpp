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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    map<int,int> m;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});

    while(q.empty()==false)
    {
        TreeNode<int> *curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if(m.find(dist)==m.end())
        {
            m[dist] = curr->val;
        }

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