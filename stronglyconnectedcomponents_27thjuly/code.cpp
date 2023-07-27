#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<int> adj[],stack<int> &st,vector<int> &vis)
{
    vis[i]=1;
    for(auto x:adj[i])
    {
        if(!vis[x])
        {
            dfs(x,adj,st,vis);
        }
    }
    st.push(i);
}

void dfs2(int i,vector<int> &vis,vector<int> radj[],vector<int> &v)
{
    vis[i]=1;
    for(auto it:radj[i])
    {
        if(vis[it]==0)
        {
            dfs2(it,vis,radj,v);
        }
    }
    v.push_back(i);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    for(auto x:edges)
    {
        adj[x[0]].push_back(x[1]);
    }

    stack<int> st;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,st,vis);
        }
    }

    vector<int> radj[n];
    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
        for(auto it:adj[i])
        {
            radj[it].push_back(i);
        }
    }

    vector<vector<int>> ans;
    while(st.empty()==false)
    {
        int curr = st.top();
        st.pop();
        vector<int> v;
        if(vis[curr]==0)
        {
            dfs2(curr,vis,radj,v);
        }
        ans.push_back(v);
    }

    return ans;
}