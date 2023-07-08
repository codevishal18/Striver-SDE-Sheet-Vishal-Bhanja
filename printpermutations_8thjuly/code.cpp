#include <bits/stdc++.h>
using namespace std;

void perm(string &s,vector<string> &res,int l,int r)
{
    if(l==r)
    {
        res.push_back(s);
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            perm(s,res,l+1,r);
            swap(s[l],s[i]);
        }
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> res;
    perm(s,res,0,s.length()-1);
    return res;
}