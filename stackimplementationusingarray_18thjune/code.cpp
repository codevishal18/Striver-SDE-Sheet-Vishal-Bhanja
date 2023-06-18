#include <bits/stdc++.h>
using namespace std; 
// Stack class.
class Stack {
    int *arr;
    int top1,size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        this->size=capacity;
        arr = new int[capacity];
        top1 = -1;
    }

    void push(int num) {
        // Write your code here.
        if(size-top1>1)
        {
            top1++;
            arr[top1]=num;
        }
    }

    int pop() {
        // Write your code here.
        if(top1>=0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    
    int top() {
        // Write your code here.
        if(top1>=0)
        {
            int ans = arr[top1];
            return ans;
        }
        else
        {
            return -1;
        }
    }
    
    int isEmpty() {
        // Write your code here.
        if(top1==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    int isFull() {
        // Write your code here.
        if(top1==size)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
};