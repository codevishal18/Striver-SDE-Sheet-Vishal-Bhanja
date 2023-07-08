#include<bits/stdc++.h>
using namespace std;

int countnumbers(vector<int> r,int mid)
{
    int l = 0;
    int h = r.size()-1;
    while(l<=h)
    {
        int m = (h+l)/2;
        if(r[m]<=mid)
        {
            l=m+1;
        }
        else
        {
            h=m-1;
        }
    }

    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int minm = INT_MAX;
    int maxm = INT_MIN;

    for(int i=0;i<n;i++)
    {
        minm = min(minm,matrix[i][0]);
        maxm = max(maxm,matrix[i][m-1]);
    }
    int hn = (m*n)/2;

    while(minm<=maxm)
    {
        int mid = (maxm+minm)/2;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            count += countnumbers(matrix[i],mid);
        }

        if(count<=hn)
        {
            minm = mid+1;
        }
        else
        {
            maxm = mid-1;
        }
    }

    return minm;
}