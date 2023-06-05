#include<bits/stdc++.h>
using namespace std;

//as the array is sorted we can use binary search here and check some cases to discard some part of the search space
int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int l = 0;
	int h = arr.size()-1;
	while(l<h)
	{
		int mid = l+(h-l)/2;
		if(mid%2==0)
		{
			if(arr[mid]==arr[mid+1])
			{
				l=mid+2;
			}
			else
			{
				h=mid;
			}
		}
		else
		{
			if(arr[mid]==arr[mid-1])
			{
				l=mid+1;
			}
			else
			{
				h=mid-1;
			}
		}
	}

	return arr[l];
}