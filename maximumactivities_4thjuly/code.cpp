#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>& a,pair<int,int>& b)
{
    return a.second<b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> v;
    for(int i=0;i<start.size();i++)
    {
        v.push_back({start[i],finish[i]});
    }

    sort(v.begin(),v.end(),comp);
    int ans = 0;
    int prev = -1;
    for(auto x:v)
    {
        if(x.first>=prev)
        {
            ans++;
            prev = x.second;
        }
    }

    return ans;
}