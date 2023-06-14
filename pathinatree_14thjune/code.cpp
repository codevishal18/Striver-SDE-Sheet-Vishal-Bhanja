#include <bits/stdc++.h>
using namespace std;

    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>ans;

    int t = x;

    unordered_map<int,int>map;

    map.insert({root->data, -1});

    queue<TreeNode<int>*>q;

    q.push(root);

    while(!q.empty()){

        int sz = q.size();

        for(int i = 0; i < sz; i++){

            root = q.front();

            q.pop();

            if(root->left){

                q.push(root->left);

                map.insert({root->left->data , root->data});

            }

            if(root->right){

                q.push(root->right);

                map.insert({root->right->data, root->data});

            }

        }

    }

    while(map[x] != -1){

        ans.push_back(map[x]);

        x = map[x];

    }

    reverse(ans.begin(), ans.end());

    ans.push_back(t);

    return ans;
}
