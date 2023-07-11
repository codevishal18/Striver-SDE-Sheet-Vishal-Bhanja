#include <bits/stdc++.h>
using namespace std;

//relax all the edges n-1 times sequentially
// if(dist[u]+wt<dist[v])  u->v edge
//check for negative weight cycle in nth relaxation

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    for(int i=0;i<n-1;i++)
    {
        for(auto x:edges)
        {
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            if(dist[u]!=1e9 && dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
    }

    return dist[dest];
    // here given that no negative weight cycles are present
    // for(auto x:edges)
    // {
    //     int u = x[0];
    //         int v = x[1];
    //         int wt = x[2];

    //         if(dist[u]+wt<dist[v])
    //         {
    //             return -1; // negative weight cycle
    //         }
    // }
}