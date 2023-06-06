#include <bits/stdc++.h>
using namespace std; 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<set<int>> adj(vertex); // as in the question it is told that the neighbours will be visited in a sorted order
    for(auto e : edges){
        adj[e.first].insert(e.second);
        adj[e.second].insert(e.first);
    }
    vector<int> bfs;
    // visited array
    vector<bool> visited(vertex, false);
    // Since the graph is disconected
    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            // BFS Traversal
            // queue
            queue<int> queue;
            queue.push(i);
            while(!queue.empty()){
                int curr = queue.front();
                queue.pop();
                if(visited[curr]) continue;
                visited[curr] = true;
                bfs.push_back(curr);
                for(auto j : adj[curr]){
                    if(!visited[j])
                        queue.push(j);
                }
            }
        }
    }
    return bfs;
}