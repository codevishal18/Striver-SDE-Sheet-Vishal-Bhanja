#include<bits/stdc++.h>
using namespace std;

// using unordered map and doubly linked list
class LRUCache
{
public:
    class Node
    {
        public:
        int key,val;   //store key value pairs in each node in DLL
        Node *next;
        Node *prev;
        Node(int _key,int _val)
        {
            key = _key;
            val = _val;
        }
    };

    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    int cap; //capacity of the cache
    unordered_map<int,Node *> mp;

    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addnode(Node *newNode) //always add next to head
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void delnode(Node *delNode) //always delete the tail's prev node as it is the lru 
    {
        Node *delnext = delNode->next;
        Node *delprev = delNode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key)
    {
        // Write your code here
        if(mp.find(key)==mp.end())  //check if present
        {
            return -1;
        }
        else  //if present move to head next as it becomes mru
        {
            Node *result = mp[key];
            int res = result->val;
            mp.erase(key);
            delnode(result);
            addnode(result);
            mp[key] = head->next;
            return res;
        }
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key)!=mp.end()) //if already present remove and make it mru
        {
            Node *temp = mp[key];
            mp.erase(key);
            delnode(temp);
        }

        if(mp.size()==cap) //check for capacity and size if required remove lru
        {
            mp.erase(tail->prev->key);
            delnode(tail->prev);
        }

        addnode(new Node(key,value));
        mp[key] = head->next;
    }
};
