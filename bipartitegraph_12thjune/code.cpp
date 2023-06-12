#include<bits/stdc++.h>
using namespace std;

bool bfs(int i,vector<int> adj[],vector<int> &col)
{
	queue<int> q;
	q.push(i);
	col[i]=1;
	while(q.empty()==false)
	{
		int curr = q.front();
		q.pop();

		for(auto x:adj[curr])
		{
			if(col[x]==-1)
			{
				col[x] = 1-col[curr];
				q.push(x);
			}
			else if(col[x]==col[curr])
			{
				return false;
			}
		}
	}

	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n = edges.size();
	vector<int> adj[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(edges[i][j]==1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int> col(n,-1);
	for(int i=0;i<n;i++)
	{
		if(col[i]==-1)
		{
			if(bfs(i,adj,col)==false)
			{
				return false;
			}
		}
	}

	return true;
}