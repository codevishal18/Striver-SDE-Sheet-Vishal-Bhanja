#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int i=0;
        while(i<s.length())
        {
            if(s[i]=='M')
            {
                res += 1000;
            }
            else if(s[i]=='D')
            {
                res += 500;
            }
            else if(s[i]=='C')
            {
                if(i<s.length() && s[i+1]=='D')
                {
                    res += 400;
                    i += 1;
                }
                else if(i<s.length() && s[i+1]=='M')
                {
                    res += 900;
                    i += 1;
                }
                else
                {
                    res += 100;
                }
            }
            else if(s[i]=='L')
            {
                res += 50;
            }
            else if(s[i]=='X')
            {
                if(i<s.length() && s[i+1]=='L')
                {
                    res += 40;
                    i += 1;
                }
                else if(i<s.length() && s[i+1]=='C')
                {
                    res += 90;
                    i += 1;
                }
                else
                {
                    res += 10;
                }
            }
            else if(s[i]=='V')
            {
                res += 5;
            }
            else
            {
                if(i<s.length() && s[i+1]=='V')
                {
                    res += 4;
                    i += 1;
                }
                else if(i<s.length() && s[i+1]=='X')
                {
                    res += 9;
                    i += 1;
                }
                else
                {
                    res += 1;
                }
            }
            i++;
        }
        return res;
    }
};