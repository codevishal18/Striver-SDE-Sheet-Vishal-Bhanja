#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int curr=0;
    int ans=0;
    int m=prices[0];

    for(int i=1;i<prices.size();i++)
    {     
          if(m>prices[i])
          {
              m=prices[i];
          }

          if(m<prices[i])
          {
              curr=prices[i]-m;
              if(ans<curr)
                ans = curr;
          }
    }

    return ans;
}