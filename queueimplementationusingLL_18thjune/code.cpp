#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class Queue {
private:
    Node *f;
    Node *r;

public:
    Queue() {
        // Implement the Constructor
        f = NULL;
        r = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(f==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        Node *temp = new Node(data);
        if(isEmpty())
        {
            f = temp;
            r = temp;
        }
        else
        {
            r->next = temp;
            r = r->next;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            int ans = f->data;
            Node *temp = f;
            f=f->next;
            if(f==NULL)
            {
                r=NULL;
            }
            delete temp;
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return f->data;
        }
    }
};