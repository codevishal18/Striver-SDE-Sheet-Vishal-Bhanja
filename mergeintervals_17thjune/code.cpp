#include <bits/stdc++.h>
using namespace std; 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    int n = intervals.size();
    if(n<=1)
    {
        return intervals;
    }
    vector<vector<int>> ans;
    int ind = 0;
    sort(intervals.begin(),intervals.end());
    ans.push_back(intervals[0]);
    for(int i=1;i<n;i++)
    {
        if(intervals[i][0]<=ans[ind][1])
        {
            ans[ind][1] = max(ans[ind][1],intervals[i][1]);
        }
        else
        {
            ind++;
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}
