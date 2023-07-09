#include <bits/stdc++.h>
using namespace std;

void insertsorted(stack<int> &s,int num)
{
	if(s.empty() || num>s.top())
	{
		s.push(num);
		return;
	}

	int x = s.top();
	s.pop();
	insertsorted(s,num);
	s.push(x);
}

void sortStack(stack<int> &s)
{
	// Write your code here
	if(s.empty())
	{
		return;
	}

	int num = s.top();
	s.pop();
	sortStack(s);
	insertsorted(s,num);
}