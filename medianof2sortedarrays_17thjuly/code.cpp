#include<bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	if(a.size() > b.size())  // as we have to perform the binary search in the minimum size array
	{
		median(b, a);
	}

    int n1 = a.size();
    int n2 = b.size();
    int l=0,r=n1;

    while(l<=r)
	{
		//check how many elements must be on left of median element
        int m1 = l+(r-l)/2; //take these from array1
        int m2 = (n1+n2+1)/2 - m1;  //take the remaining elememts from array2
        int l1 = m1 == 0 ? INT_MIN : a[m1 - 1];
        int l2 = m2 == 0 ? INT_MIN : b[m2 - 1];
        int r1 = m1 == n1 ? INT_MAX : a[m1];
        int r2 = m2 == n2 ? INT_MAX : b[m2]; 

		//check for max of array1 left side and min of array2 right side
		//check for max of array2 left side and min of array1 left side
		//check for total elements even or odd
        if(l1 <= r2 and l2 <= r1)
		{
            if((n1 + n2) % 2 == 0)
			{
                return ((max(l1, l2)) + (min(r1, r2))) / 2.0;
            }
			else
			{
                return max(l1, l2);
            }
        }
		else if(l1 > r2) //have to decrease l1
		{
            r = m1 - 1; 
        }
		else   
		{
            l = m1 + 1;
        }
	}
}