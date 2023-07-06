#include<bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i = 0;
    int j = 0;
    int maxm = 0;
    int c0 = 0;

    while(j<n)
    {
        if(arr[j]==0)
        {
            c0++;
        }

        while(c0>k)
        {
            if(arr[i]==0)
            {
                c0--;
            }
            i++;
        }

        maxm = max(maxm,j-i+1);
        j++;
    }

    return maxm;
}
