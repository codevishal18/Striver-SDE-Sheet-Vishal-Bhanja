#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	long long csum = 0;
	long long cssum = 0;
	long long asum = (long long)(n*(n+1))/2;
	long long assum = ((long long)(n)*(long long)(n+1)*(long long)(2*n+1))/6;
	for(auto x:arr)
	{
		csum += (long long)x;
		cssum += (long long)x * (long long)x; 
	}

	long long diff = csum - asum;
	long long sqdiff = cssum - assum;

	long long sum = sqdiff/diff;
	long long repeating = (sum+diff)/2;
	long long missing = sum - repeating;

	return {(int)missing,(int)repeating};
}
