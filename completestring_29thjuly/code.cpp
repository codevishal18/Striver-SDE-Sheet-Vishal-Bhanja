#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    TrieNode *links[26];
    bool isEnd = false;

};

void insert(TrieNode *root,string s)
{
    TrieNode *curr = root;
    for(int i=0;i<s.length();i++)
    {
        if(curr->links[s[i]-'a']==NULL)
        {
            curr->links[s[i]-'a'] = new TrieNode();
        }
        curr = curr->links[s[i]-'a'];
    }

    curr->isEnd = true;
}

bool search(TrieNode *root,string s)
{
    TrieNode *curr = root;
    for(int i=0;i<s.size();i++)
    {
        curr = curr->links[s[i]-'a'];
        if(curr->isEnd==false)
        {
            return false;
        }
    }

    return true;
}

string completeString(int n, vector<string> &a){
    // Write your code here.
    TrieNode *root = new TrieNode();
    for(auto s:a)
    {
        insert(root,s);
    }

    string ans;
    for(int i=0;i<a.size();i++)
    {
        if(search(root,a[i]))
        {
            if(a[i].length()>ans.length())
            {
                ans = a[i];
            }
            else if(a[i].length()==ans.length())
            {
                if(ans>a[i])
                {
                    ans = a[i];
                }
            }
        }
    }

    if(ans.length()==0)
    {
        return "None";
    }

    return ans;
}