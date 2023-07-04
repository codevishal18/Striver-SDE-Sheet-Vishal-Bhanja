#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int res = 0;
    int curr = 1;
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            continue;
        }

        if(arr[i]==arr[i-1]+1)
        {
            curr++;
        }
        else
        {
            res = max(res,curr);
            curr = 1;
        }
    }

    res = max(res,curr);
    return res;
}