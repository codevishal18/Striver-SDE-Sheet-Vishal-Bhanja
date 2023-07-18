#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
public:
    int capacity;
    int minFreq;
    unordered_map<int,pair<int,int>> cache;
    unordered_map<int,list<int>::iterator> keynode;
    unordered_map<int,list<int>> freq;  

    LFUCache(int capacity)
    {
        // Write your code here.
        this->capacity=capacity;
        minFreq = 0;
    }

    int get(int key)
    {
        // Write your code here.
        if(cache.find(key)==cache.end())
        {
            return -1;
        }
        else
        {
            int f = cache[key].second;
            freq[f].erase(keynode[key]);
            f++;
            freq[f].push_front(key);
            keynode[key] = freq[f].begin();
            
            if(freq[minFreq].empty())
            {
                minFreq++;
            }
            return cache[key].first;   
        }
    }

    void put(int key, int value)
    {
        // Write your code here.
        if(cache.find(key)!=cache.end())
        {
            int f = cache[key].second;
            freq[f].erase(keynode[key]);
            f++;
            freq[f].push_front(key);
            keynode[key] = freq[f].begin();
            
            if(freq[minFreq].empty())
            {
                minFreq++;
            }
            cache[key].first = value;
            return;
        }

        if(capacity==cache.size())
        {
            int key = freq[minFreq].back();
            cache.erase(key);
            keynode.erase(key);
            freq[minFreq].pop_front(); //
        }

        cache[key] = {value,1};
        minFreq = 1;
        freq[1].push_front(key);
        keynode[key] = freq[1].begin();
    }
};
