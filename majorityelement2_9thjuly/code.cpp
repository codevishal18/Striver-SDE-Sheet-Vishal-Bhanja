#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int> ans;
    int c1=0,c2=0,e1=0,e2=0;
    for(auto x:arr)
    {
        if(x==e1)
        {
            c1++;
        }
        else if(x==e2)
        {
            c2++;
        }
        else if(c1==0)
        {
            e1 = x;
            c1++;
        }
        else if(c2==0)
        {
            c2++;
            e2 = x;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    c1=0,c2=0;
    for(auto x:arr)
    {
        if(x==e1)
        {
            c1++;
        }

        if(x==e2)
        {
            c2++;
        }
    }

    if(c1>n/3)
    {
        ans.push_back(e1);
    }

    if(c2>n/3)
    {
        ans.push_back(e2);
    }

    return ans;
}