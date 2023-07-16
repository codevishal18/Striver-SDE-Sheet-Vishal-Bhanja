#include<bits/stdc++.h>
using namespace std;

int maximumMeetings(vector<int> &start, vector<int> &finish)
{
    // Write your code here.
    vector<pair<int,pair<int,int>>> ans;
    for(int i = 0;i < start.size();i++)
    {
        ans.push_back({finish[i],{i,start[i]}});
    }
    //sort the ans vector accoding to finish value


    sort(ans.begin(),ans.end());

    int e = -1;
    int count = 0;

    for(auto val : ans)
    {
        if(val.second.second > e)
        {
            count++;
            e = val.first;
        }
    }
    return count;
}