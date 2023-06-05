#include <bits/stdc++.h>
using namespace std; 
void sort012(int *arr, int n)
{
   //   Write your code here
   int i0 = 0;
   int i = 0;
   while(i<n)
   {
      if(arr[i]==0)
      {
         swap(arr[i],arr[i0]);
         i0++;
      }
      i++;
   }

   int i1 = i0;
   i = i0;
   while(i<n)
   {
      if(arr[i]==1)
      {
         swap(arr[i],arr[i1]);
         i1++;
      }
      i++;
   }
}