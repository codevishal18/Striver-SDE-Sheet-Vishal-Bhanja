#include<bits/stdc++.h>
using namespace std;

//using the xor to find the single element
int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int res = 0;
	for(int i=0;i<arr.size();i++)
	{
		res ^= arr[i];
	}

	return res;
}