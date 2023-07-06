#include <bits/stdc++.h>
using namespace std;

void solve(int i,int j,vector<vector<int>> &maze,vector<vector<int>> &ans,vector<int> &temp,vector<vector<int>> &pv,int n)
{
  if(i==n-1 && j==n-1)
  {
    ans.push_back(temp);
    return;
  }

  int dr[] = {0,0,1,-1};
  int dc[] = {1,-1,0,0};

  for(int k=0;k<4;k++)
  {
    int nr = i+dr[k];
    int nc = j+dc[k];

    if(nr>=0 && nr<n && nc>=0 && nc<n && pv[nr][nc]==0 && maze[nr][nc]==1)
    {
      pv[nr][nc]=1;
      temp[n*nr+nc]=1;
      solve(nr,nc,maze,ans,temp,pv,n);
      pv[nr][nc]=0;
      temp[n*nr+nc]=0;
    }
  }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<int> temp(n*n,0);
  vector<vector<int>> ans;
  vector<vector<int>> pv(n,vector<int>(n,0));
  pv[0][0]=1;
  temp[0]=1;
  solve(0,0,maze,ans,temp,pv,n);
  return ans;
}