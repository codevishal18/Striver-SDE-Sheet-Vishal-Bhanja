#include <bits/stdc++.h>
using namespace std; 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long csum = 0;
    long long max_sum = INT_MIN;
    for(int i=0;i<n;i++)
    {
        csum += arr[i];
        if(csum<0)
        {
            csum = 0;
        } 
        max_sum = max(max_sum,csum);
    }

    return max_sum;
}