#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    TrieNode *links[26];
    int last,between;
    TrieNode()
    {
        last = 0;
        between = 0;
    }
};

class Trie{

    public:
    TrieNode *root;

    Trie(){
        // Write your code here.
        root = new TrieNode();
    }

    void insert(string &word){
        // Write your code here.
        TrieNode* temp = root;
        for(auto ch : word)
        {
            if(temp->links[ch-'a']==NULL)
            {
                temp->links[ch-'a'] = new TrieNode();
                temp->links[ch-'a']->between += 1;
            } 
            else
            {
              temp->links[ch - 'a']->between += 1;
            }
            temp = temp->links[ch-'a'];
        }
        temp->last += 1;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        TrieNode *temp = root;
        for(auto ch : word)
        {
          if (temp->links[ch - 'a'] == NULL) {
            return 0;
          }
            temp = temp->links[ch-'a'];
        }
        return temp->last;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        TrieNode *temp = root;
        for(auto ch : word)
        {
          if (temp->links[ch - 'a'] == NULL) {
            return 0;
          }
            temp = temp->links[ch-'a'];
        }
        return temp->between;
    }

    void erase(string &word){
        // Write your code here.
        TrieNode *temp = root;
        for(auto ch : word)
        {
            temp->links[ch-'a']->between-=1;
            temp = temp->links[ch-'a'];
        }
        temp->last-=1;
    }
};
