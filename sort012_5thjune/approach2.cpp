#include <bits/stdc++.h>
using namespace std; 
void sort012(int *arr, int n)
{
   //   Write your code here
   int i0 = 0;
   int i2 = n-1;
   int i = 0;
   while(i<=i2)
   {
      if(arr[i]==0)
      {
         swap(arr[i],arr[i0]);
         i0++;
         i++;
      }
      else if(arr[i]==1)
      {
         i++;
      }
      else
      {
         swap(arr[i],arr[i2]);
         i2--;
      }
   }
}