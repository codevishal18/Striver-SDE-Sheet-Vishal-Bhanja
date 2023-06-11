#include <bits/stdc++.h>
using namespace std;

void dfstoposort(int i,vector<int> adj[],vector<int> &vis,stack<int> &s)
{
    vis[i]=1;
    for(auto x:adj[i])
    {
        if(vis[x]==0)
        {
            dfstoposort(x,adj,vis,s);
        }
    }
    s.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> adj[v];
    vector<int> vis(v,0);
    for(auto e:edges)
    {
        adj[e[0]].push_back(e[1]);
    }

    stack<int> s;
    for(int i=0;i<v;i++)
    {
        if(vis[i]==0)
        {
            dfstoposort(i,adj,vis,s);
        }
    }

    vector<int> ans;
    while(s.empty()==false)
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}