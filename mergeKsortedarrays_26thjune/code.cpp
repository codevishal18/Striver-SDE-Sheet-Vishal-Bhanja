#include <bits/stdc++.h>
using namespace std; 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({kArrays[i][0],{i,0}});
    }

    while(pq.empty()==false)
    {
        int x = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        ans.push_back(x);

        if(c+1<kArrays[r].size())
        {
            pq.push({kArrays[r][c+1],{r,c+1}});
        }
    }

    return ans;
}
