#include <bits/stdc++.h>
using namespace std; 
class Stack {
	// Define the data members.
    queue<int> q1;
    queue<int> q2;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element) {
        // Implement the push() function.
        q1.push(element);
    }

    int pop() {
        // Implement the pop() function.
        if(q1.empty()==true)
        {
            return -1;
        }

        int ans = -1;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        ans = q1.front();
        q1.pop();
        while(q2.empty()==false)
        {
            q1.push(q2.front());
            q2.pop();
        }

        return ans;
    }

    int top() {
        // Implement the top() function.
        if(q1.empty()==true)
        {
            return -1;
        }

        int ans = -1;
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        ans = q1.front();
        q2.push(ans);
        q1.pop();
        while(q2.empty()==false)
        {
            q1.push(q2.front());
            q2.pop();
        }

        return ans;
    }
};