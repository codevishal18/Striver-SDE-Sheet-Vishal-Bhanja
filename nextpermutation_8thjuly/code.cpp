#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int ind = -1;
    for(int i=n-2;i>=0;i--) //find an element that is smaller than than the next element from backside
    {
        if(permutation[i]<permutation[i+1])
        {
            ind=i;
            break;
        }
    }

    if(ind==-1) //if the sequence is in decreasing order we just need to return the ascending order sequence
    {
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }

    for(int i=n-1;i>ind;i--)  //check for a element greater than the index element from back and swap them
    {
        if(permutation[i]>permutation[ind])
        {
            swap(permutation[i],permutation[ind]);
            break;
        }
    }

    reverse(permutation.begin()+ind+1,permutation.end());  // reverse all the elements ahead of the index element
    return permutation;
}