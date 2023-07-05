#include <bits/stdc++.h>
using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	sort(a.begin(),a.end(),greater<int>());
	sort(b.begin(),b.end(),greater<int>());
	priority_queue<pair<int,int>> pq;
	for(auto x:a)
	{
		pq.push({x+b[0],0});
	}

	vector<int> ans;
	while(k-- && pq.empty()==false)
	{
		int sum = pq.top().first;
		int ind = pq.top().second;
		ans.push_back(sum);
		pq.pop();
		if(ind+1<b.size())
		{
			pq.push({sum-b[ind]+b[ind+1],ind+1});
		}
	}

	return ans;
}