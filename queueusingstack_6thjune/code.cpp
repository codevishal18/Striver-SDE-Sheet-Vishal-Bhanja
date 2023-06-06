#include<bits/stdc++.h>
using namespace std;
class Queue {
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(s2.empty()==false)
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        while(s1.empty()==false)
        {
            s2.push(s1.top());
            s1.pop();
        }

        if(s2.empty()==true)
        {
            return -1;
        }
        int a = s2.top();
        s2.pop();
        return a;
    }

    int peek() {
        // Implement the peek() function here.
        while(s1.empty()==false)
        {
            s2.push(s1.top());
            s1.pop();
        }

        if(s2.empty()==true)
        {
            return -1;
        }
        return s2.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.empty()&&s2.empty();
    }
};