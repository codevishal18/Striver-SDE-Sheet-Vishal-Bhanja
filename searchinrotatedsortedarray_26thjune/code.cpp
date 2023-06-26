#include<bits/stdc++.h>
using namespace std;

int search(int* arr, int n, int key) {
    // Write your code here.
    int l = 0;
    int h = n-1;
    while(l<=h)
    {
        int mid = l+(h-l)/2;
        if(arr[mid]==key)
        {
            return mid;
        }

        if(arr[l]<=arr[mid])
        {
            if(key>=arr[l] && key<arr[mid])
            {
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        else if(arr[l]>=arr[mid])
        {
            if(key>arr[mid] && key<=arr[h])
            {
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
    }

    return -1;
}