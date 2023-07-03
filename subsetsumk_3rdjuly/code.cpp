#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int> &curr,vector<vector<int>> &ans,vector<int> &arr,int k)
{
    if(i==arr.size())
    {
        if(k==0)
        {
            ans.push_back(curr);
        }
        return;
    }

    curr.push_back(arr[i]);
    solve(i+1,curr,ans,arr,k-arr[i]);
    curr.pop_back();
    solve(i+1,curr,ans,arr,k);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> curr;
    int i = 0;
    int sum = 0;
    solve(i,curr,ans,arr,k);
    return ans;
}