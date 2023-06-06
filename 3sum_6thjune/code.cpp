#include <bits/stdc++.h>
using namespace std; 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>> v;
	for(int i=0;i<n-2;i++)
	{
		int j = i+1;
		int k = n-1;
		int r = K-arr[i];
		while(j<k)
		{
			int sum = arr[j]+arr[k];
			if(sum>r)
			{
				k--;
			}
			else if(sum<r)
			{
				j++;
			}
			else
			{
				int x = arr[j];
				int y = arr[k];
				v.push_back({arr[i],arr[j],arr[k]});
				while(arr[j]==x && j<k)
				{
					j++;
				}

				while(arr[k]==y && j<k)
				{
					k--;
				}
			}
		}

		while(i<n-2 && arr[i]==arr[i+1])
		{
			i++;
		}
	}

	return v;
}