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

void solve(TreeNode<int> *root, int k, int &cnt, int &ans) {

    if(root == NULL) return;

    solve(root->left, k, cnt, ans);
    cnt++;

    if(cnt == k) {
        ans = root->data;
        return;
    }
    solve(root->right, k, cnt, ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = INT_MIN;
    int cnt = 0;
    solve(root, k, cnt, ans);
    return ans;
}