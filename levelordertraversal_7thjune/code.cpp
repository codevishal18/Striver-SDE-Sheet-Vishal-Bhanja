#include <bits/stdc++.h>
using namespace std; 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
    if(root == NULL){
        return {};
    }
    
    queue<BinaryTreeNode<int> *> q;
    q.push(root);    

    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        ans.push_back(front->val);

        if (front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }

    return ans;
}