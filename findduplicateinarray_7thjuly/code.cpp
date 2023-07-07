#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums, int n){
	// Write your code here.
	// can sort and find the duplicate
	// can use hashing to see if the element is already visited
	int slow = nums[0];
	int fast = nums[0];
	while(1)
	{
		slow = nums[slow];
		fast = nums[nums[fast]];
		if(slow==fast)
		{
			break;
		}
	}

	slow = nums[0];
	while(slow!=fast)
	{
		slow = nums[slow];
		fast = nums[fast];
	}

	return slow;
}
