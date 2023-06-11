#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &v)
{
    vis[i]=1;
    v.push_back(i);
    for(auto x:adj[i])
    {
        if(vis[x]==0)
        {
            dfs(x,adj,vis,v);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    for(int i=0;i<E;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<vector<int>> ans;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++)
    {
      if (vis[i] == 0) {
        vector<int> v;
        dfs(i, adj, vis, v);
        ans.push_back(v);
      }
    }

    return ans;
}