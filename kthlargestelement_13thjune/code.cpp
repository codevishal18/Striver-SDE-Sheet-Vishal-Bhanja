#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<size;i++)
	{
		if(pq.size()<K)
		{
			pq.push(arr[i]);
		}
		else
		{
			if(pq.top()<arr[i])
			{
				pq.pop();
				pq.push(arr[i]);
			}
		}
	}

	return pq.top();
}