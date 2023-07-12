#include <bits/stdc++.h>
using namespace std;

struct node{
	int wt;
	int u;
	int v;

	node(int child, int parent, int weight){
		wt = weight;
		u = child;
		v= parent;
	}
};

bool compares(node a, node b){
	return a.wt < b.wt;
}

int findPar(int node, vector<int>&parent){
	if(node==parent[node]){
		return node;
	}
	return parent[node] = findPar(parent[node],parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	vector<node> vec;
	for(auto i: graph){
		vec.push_back(node(i[0],i[1],i[2]));
	}

	sort(vec.begin(), vec.end(), compares);


	int min_cost = 0;

	vector<int> rank(n+1,0);
	vector<int>parent(n+1);
	for(int i=0; i<=n; i++){
		parent[i] = i;
	}


	for(auto i: vec){
		int wt = i.wt;
		int u = i.u;
		int v = i.v;

		if(findPar(u,parent) != findPar(v,parent)){
			min_cost += wt;
			unionn(u,v,parent,rank);
		}
	}
	return min_cost;

}