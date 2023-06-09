#include<bits/stdc++.h>
using namespace std;

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here.
    queue<pair<pair<int,int>,int>> q;
    int vis[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});
                vis[i][j]=1;
            }
            else
            {
                vis[i][j]=0;
            }
        }
    }

    int delrow[] = {0,-1,0,1};
    int delcol[] = {-1,0,1,0};
    int ans = 0;
    while(q.empty()==false)
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        ans = max(ans,t);
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nr = r+delrow[i];
            int nc = c+delcol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1)
            {
                q.push({{nr,nc},t+1});
                vis[nr][nc]=1;
                grid[nr][nc]=2;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                return -1;
            }
        }
    }

    return ans; 
}