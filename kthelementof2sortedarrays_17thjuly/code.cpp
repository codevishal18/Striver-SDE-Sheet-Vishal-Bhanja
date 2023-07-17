#include<bits/stdc++.h>
using namespace std;
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    if(m<n) return ninjaAndLadoos(row2, row1, n, m, k);  //have to perform binary search on the smaller array

    int left = max(0, k-n);  //min no of elements to be taken from array1
    int right = min(k, m);  //max no of elements to be taken from array1
    int mid;
    while(left<=right)
    {
        mid = (left+right)>>1;
        int mid2 = k-mid;

        int l1 = mid?    row1[mid-1]:INT_MIN;
        int l2 = mid2?   row2[mid2-1]: INT_MIN;
        int r1 = mid<m?  row1[mid]: INT_MAX;
        int r2 = mid2<n? row2[mid2]: INT_MAX;

        if(l1<=r2 and l2<=r1) return max(l1, l2);
        else if(l1>r2) right = mid-1;
        else left = mid+1;
    }
    return 0;
}