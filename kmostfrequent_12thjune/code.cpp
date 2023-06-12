#include <bits/stdc++.h>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(auto x:mp)
    {
        if(pq.size()<k)
        {
            pq.push({x.second,x.first});
        }
        else
        {
            if(pq.top().first<x.second)
            {
                pq.pop();
                pq.push({x.second,x.first});
            }
        }
    }

    while(pq.empty()==false)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(),ans.end());
    return ans;
}