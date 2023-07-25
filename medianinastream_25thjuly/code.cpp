#include<bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n){
	// Write your code here
	priority_queue<int> mxh;
    priority_queue<int,vector<int>,greater<int>> mnh;
	vector<int> v;

    for(int i=0;i<n;i++)
    {
        if(mxh.empty() || mxh.top()>=arr[i])
        {
            mxh.push(arr[i]);
        }
        else
        {
            mnh.push(arr[i]);
        }

        if(mxh.size()>mnh.size()+1)
        {
            mnh.push(mxh.top());
            mxh.pop();
        }
        else if(mnh.size()>mxh.size()+1)
        {
            mxh.push(mnh.top());
            mnh.pop();
        }

        if(mnh.size()>mxh.size())
        {
            v.push_back(mnh.top());
        }
        else if(mxh.size()>mnh.size())
        {
            v.push_back(mxh.top());
        }
        else
        {
            v.push_back((mxh.top()+mnh.top())/2);
        }
    }

	return v;
}
