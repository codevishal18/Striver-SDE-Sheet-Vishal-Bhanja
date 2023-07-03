#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int> &ans,vector<int> &nums,int sum)
{
	if(i==nums.size())
	{
		ans.push_back(sum);
		return;
	}

	solve(i+1,ans,nums,sum+nums[i]);
	solve(i+1,ans,nums,sum);
}

vector<int> subsetSum(vector<int> &nums){
	// Write your code here.
	int i = 0;
	vector<int> ans;
	int sum = 0;
	solve(i,ans,nums,0);
	sort(ans.begin(),ans.end());
	return ans;	
}