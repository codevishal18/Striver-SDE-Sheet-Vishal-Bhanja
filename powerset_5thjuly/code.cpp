#include <bits/stdc++.h>
using namespace std;

void solve(int i,vector<int> &curr,vector<vector<int>> &ans,vector<int> &v)
{
    if(i==v.size())
    {
        ans.push_back(curr);
        return;
    }

    curr.push_back(v[i]);
    solve(i+1,curr,ans,v);
    curr.pop_back();
    solve(i+1,curr,ans,v);
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int i = 0;
    vector<int> curr;
    vector<vector<int>> ans;
    solve(i,curr,ans,v);
    return ans;
}