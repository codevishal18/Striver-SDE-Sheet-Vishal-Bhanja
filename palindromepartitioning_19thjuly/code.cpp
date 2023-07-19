#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &st,int s,int e)
{
    while(s<=e)
    {
        if(st[s]!=st[e])
        {
            return false;
        }
        s++;
        e--;
    }

    return true;
}

void solve(int i,string &s,vector<string> &v,vector<vector<string>> &ans)
{
    if(i==s.length())
    {
        ans.push_back(v);
        return;
    }

    for(int j=i;j<s.length();j++)
    {
        if(isPalindrome(s,i,j))
        {
            v.push_back(s.substr(i,j-i+1));
            solve(j+1,s,v,ans);
            v.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> v;
    solve(0,s,v,ans);
    return ans;
}