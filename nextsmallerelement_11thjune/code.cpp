#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> v;
    v.push_back(-1);
    s.push(arr[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        while(s.empty()==false && s.top()>=arr[i])
        {
            s.pop();
        }

        if(s.empty()==true)
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(s.top());
        }

        s.push(arr[i]);
    }

    reverse(v.begin(),v.end());
    return v;
}