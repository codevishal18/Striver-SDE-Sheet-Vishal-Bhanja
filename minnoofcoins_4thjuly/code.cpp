#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> arr = {1000,500,100,50,20,10,5,2,1};
    int ans = 0;
    for(auto x:arr)
    {
        ans += (amount/x);
        amount %= x;
    }

    return ans;
}
