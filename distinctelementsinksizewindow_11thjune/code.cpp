#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	unordered_map<int,int> m;
    int i = 0;
    vector<int> ans;
    while(i<k)
    {
        m[arr[i]]++;
        i++;
    }

    ans.push_back(m.size());
    for(int i=k;i<arr.size();i++)
    {
        m[arr[i-k]]--;
        if(m[arr[i-k]]==0)
        {
            m.erase(arr[i-k]);
        }

        m[arr[i]]++;
        ans.push_back(m.size());
    }

    return ans;
}
