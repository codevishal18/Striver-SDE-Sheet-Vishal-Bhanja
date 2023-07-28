#include<bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode
{
    public:
    TrieNode *links[26];
    bool end = false;

    bool containskey(char ch)
    {
        return links[ch-'a']!=NULL;
    }

    void put(char ch,TrieNode *n)
    {
        links[ch-'a'] = n;
    }

    TrieNode *get(char ch)
    {
        return links[ch-'a'];
    }

    void setend()
    {
        end = true;
    }

    bool isend()
    {
        return end;
    }
};

class Trie {

public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *n = root;
        for(int i=0;i<word.length();i++)
        {
            if(!n->containskey(word[i]))
            {
                TrieNode *temp = new TrieNode;
                n->put(word[i],temp);
            }

            n = n->get(word[i]);
        }

        n->setend();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *n = root;
        for(int i=0;i<word.length();i++)
        {
            if(!n->containskey(word[i]))
            {
                return false;
            }

            n = n->get(word[i]);
        }

        return n->isend();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *n = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!n->containskey(prefix[i]))
            {
                return false;
            }

            n = n->get(prefix[i]);
        }

        return true;
    }
};