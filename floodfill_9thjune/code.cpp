#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image,int x,int y,int oc,int nc)
{
    int n = image.size();
    int m = image[0].size();

    if(x<0 || x>=n || y<0 || y>=m || image[x][y]!=oc)
    {
        return;
    }

    image[x][y]=nc;
    dfs(image,x+1,y,oc,nc);
    dfs(image,x,y+1,oc,nc);
    dfs(image,x-1,y,oc,nc);
    dfs(image,x,y-1,oc,nc);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int nc)
{
    // Write your code here.
    int oc = image[x][y];
    if(oc==nc)
    {
        return image;
    }

    dfs(image,x,y,oc,nc);

    return image;
}