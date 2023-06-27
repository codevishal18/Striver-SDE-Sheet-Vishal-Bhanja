#include<bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int i = 0;
    int j = 0;
    int maxm = 0;
    int curr = 0;
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            i++;
            curr++;
        }
        else
        {
            j++;
            curr--;
        }

        maxm = max(maxm,curr);
    }    

    return maxm;
}