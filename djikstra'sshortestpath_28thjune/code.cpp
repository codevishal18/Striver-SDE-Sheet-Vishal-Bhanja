#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>> adj[vertices];
    for(auto x:vec)
    {
        adj[x[0]].push_back({x[1],x[2]});
        adj[x[1]].push_back({x[0],x[2]});
    }

    vector<int> dist(vertices,INT_MAX);
    set<pair<int,int>> s;
    s.insert({0,source});
    dist[source] = 0;

    while(s.empty()==false)
    {
        pair<int,int> p = *(s.begin());
        s.erase(s.begin());

        for(auto x:adj[p.second])
        {
            if(p.first+x.second<dist[x.first])
            {
                auto y = s.find({dist[x.first],x.first});
                if(y!=s.end())
                {
                    s.erase(y);
                }

                dist[x.first] = p.first+x.second;
                s.insert({dist[x.first],x.first});
            }
        }
    }

    return dist;
}
