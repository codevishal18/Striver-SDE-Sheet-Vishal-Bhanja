#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> v;
   map<int,int> mp;

   for(int i=0;i<arr.size();i++)
   {
      int r = s-arr[i];
      if(mp.find(r)!=mp.end())
      {
         int minm = min(r,arr[i]);
         int maxm = max(r,arr[i]);
         for(int i=0;i<mp[r];i++)
         {
            v.push_back({minm,maxm});
         }
      }
      mp[arr[i]]++;
   }

   sort(v.begin(),v.end());
   return v;
}