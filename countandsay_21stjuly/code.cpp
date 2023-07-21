#include <bits/stdc++.h>
using namespace std;

string writeAsYouSpeak(int n) 
{
	// Write your code here.
	if(n==1)
	{
		return "1";
	}

	string s = writeAsYouSpeak(n-1);
	int cnt = 1;
	string ans = "";
	for(int i=0;i<s.size();i++)
	{
		if(i<s.size()-1 && s[i]==s[i+1])
		{
			cnt++;
		}
		else
		{
			ans += char(cnt+int('0'));
			ans += s[i];
			cnt = 1;
		}
	}

	return ans;	
}