#include<bits/stdc++.h>
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

int solve(TreeNode<int> *root,int &ans)
{
    if(root==NULL)
    {
        return 0;
    }

    int lh = solve(root->left,ans);
    int rh = solve(root->right,ans);
    ans = max(ans,lh+rh);
    return 1+max(lh,rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans = 0;
    solve(root,ans);
    return ans;
}
