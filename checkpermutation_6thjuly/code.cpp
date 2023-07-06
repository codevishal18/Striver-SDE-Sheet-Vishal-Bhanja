#include <bits/stdc++.h>
using namespace std;
 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.length()!=str2.length())
    {
        return false;
    }
    vector<int> v(26,0);
    for(int i=0;i<str1.length();i++)
    {
        v[str1[i]-'a']++;
        v[str2[i]-'a']--;
    }

    for(int i=0;i<26;i++)
    {
        if(v[i]!=0)
        {
            return false;
        }
    }

    return true;
}