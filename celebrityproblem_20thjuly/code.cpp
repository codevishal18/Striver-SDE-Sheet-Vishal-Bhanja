#include <bits/stdc++.h>
using namespace std;
 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) 
{
 	// Write your code here.
	// Create a stack and push all n people onto the stack.
	stack<int> st;
	for (int i=0;i<n;i++) 
	{
		st.push(i);
	}

	// Iterate through the stack and eliminate all non-celebrities.
	while(st.size()>1) 
	{
		int t1 = st.top();
		st.pop();

		int t2 = st.top();
		st.pop();

		if (knows(t1, t2)) 
		{
			st.push(t2);
		} 
		else 
		{
			st.push(t1);
		}
	}

	// Return the only person left on the stack.
	int pCeleb = st.top();

	// Check if pCeleb is actually the celebrity.
	for (int i=0;i<n;i++) 
	{
		if(i==pCeleb) 
		{
			continue;
		}

		if(knows(pCeleb,i)) 
		{
			return -1;
		}

		if(!knows(i, pCeleb)) 
		{
			return -1;
		}
	}

	return pCeleb;
}