#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    TrieNode *links[26];
    bool isEnd = false;
};

void insert(TrieNode *root,string &s,int &ans)
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

    if(curr->isEnd==false)
    {
        ans++;
        curr->isEnd = true;
    }
}

int distinctSubstring(string &word) {
    //  Write your code here.
    int l = word.length();
    TrieNode *temp = new TrieNode();
    int ans = 0;
    for(int i=0;i<l;i++)
    {
        string s;
        for(int j=i;j<l;j++)
        {
            s += word[j];
            insert(temp,s,ans);
        }
    }

    return ans;
}
