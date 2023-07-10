#include<bits/stdc++.h>
using namespace std;

long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    vector<long long> lg(n),rg(n);
    lg[0]=arr[0];
    rg[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
    {
        lg[i] = max(arr[i],lg[i-1]);
        rg[n-i-1] = max(arr[n-i-1],rg[n-i]);
    }

    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += min(rg[i],lg[i])-arr[i];
    }

    return ans;
}