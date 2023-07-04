#include<bits/stdc++.h>
using namespace std;

void help(int i,vector<int>&arr,int target,vector<int>&sub,vector<vector<int>>&ans){
	if(i==arr.size())
	{
		if(target==0){
			ans.push_back(sub);
		}
		return;
	}
	if(arr[i]<=target){
        sub.push_back(arr[i]);
        help(i+1,arr,target-arr[i],sub,ans);
        sub.pop_back();
    }
    while(i+1<arr.size() && arr[i]==arr[i+1]) i++;
    help(i+1,arr,target,sub,ans);
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	vector<int>sub;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    help(0,arr,target,sub,ans);
    
    return ans;
}
