#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    //Write your code here.
    unordered_map<int,int> mp;
    int cx = 0;
    int res = 0;

    for(int i=0;i<arr.size();i++)
    {
        cx ^= arr[i];
        if(cx==x)
        {
            res++;
        }

        int temp = cx^x;
        if(mp.find(temp)!=mp.end())
        {
            res += mp[temp];
        }

        mp[cx]++;
    }

    return res;
}