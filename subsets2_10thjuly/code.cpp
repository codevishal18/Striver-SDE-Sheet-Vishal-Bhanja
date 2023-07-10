#include <bits/stdc++.h>
using namespace std;

void solve(int i,vector<int> &arr,vector<int> &curr,vector<vector<int>> &ans)
{
    ans.push_back(curr);
    for(int j=i;j<arr.size();j++)
    {
        if(j!=i && arr[j]==arr[j-1])
        {
            continue;
        }

        curr.push_back(arr[j]);
        solve(j+1,arr,curr,ans);
        curr.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> curr;
    sort(arr.begin(),arr.end());
    solve(0,arr,curr,ans);
    return ans;
}