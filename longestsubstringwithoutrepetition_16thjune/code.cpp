#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input)
{
    //Write your code here
    vector<int> v(26,0);
    int j = 0;
    int maxm = 1;
    for(int i=0;i<input.length();i++)
    {
        v[input[i]-'a']++;

        while(v[input[i]-'a']>1)
        {
            v[input[j]-'a']--;
            j++;
        }

        maxm = max(maxm,i-j+1);
    }

    return maxm;
}