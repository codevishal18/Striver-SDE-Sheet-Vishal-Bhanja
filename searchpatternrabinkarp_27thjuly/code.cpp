#include<bits/stdc++.h>
using namespace std;

vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	int n = text.length();
	int m = pattern.length();
	vector<int> v;

	if(m>n)
	{
		return v;
	}

	int d = 256;
	int q = 101;

	int p = 0;
	int t = 0;
	int h = 1;

	for(int i=0;i<m-1;i++)
	{
		h = (h*d)%q;
	}

	for(int i=0;i<m;i++)
	{
		p = (p*d + pattern[i])%q;
		t = (t*d + text[i])%q;
	}

	for(int i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			int j;
			for(j=0;j<m;j++)
			{
				if(pattern[j]!=text[i+j])
				{
					break;
				}
			}

			if(j==m)
			{
				v.push_back(i+1);
			}
		}

		if(i<n-m)
		{
			t = (d*(t-text[i]*h)+text[i+m])%q;

			if(t<0)
			{
				t += q;
			}
		}
	}

	return v;
}
