#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,int** arr,vector<vector<int>> &vis,int n,int m)
{
   if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || arr[i][j]==0)
   {
      return;
   }

   vis[i][j]=1;
   dfs(i,j-1,arr,vis,n,m);
   dfs(i-1,j-1,arr,vis,n,m);
   dfs(i-1,j,arr,vis,n,m);
   dfs(i-1,j+1,arr,vis,n,m);
   dfs(i,j+1,arr,vis,n,m);
   dfs(i+1,j+1,arr,vis,n,m);
   dfs(i+1,j,arr,vis,n,m);
   dfs(i+1,j-1,arr,vis,n,m);
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<vector<int>> vis(n,vector<int>(m,0));
   int count = 0;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         if(arr[i][j]==1 && vis[i][j]==0)
         {
            count++;
            dfs(i,j,arr,vis,n,m);
         }
      }
   }

   return count;
}
