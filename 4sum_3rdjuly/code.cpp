#include <bits/stdc++.h>
using namespace std;

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    string s1 = "Yes";
    string s2 = "No";
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int target2 = target-arr[i]-arr[j];
            int left = j+1;
            int right = n-1;

            while(left<right)
            {
                int sum = arr[left]+arr[right];
                if(sum==target2)
                {
                    return s1;
                }
                else if(sum>target2)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }

            while(j+1<n && arr[j+1]==arr[j])
            {
                j++;
            } 
        }

        while(i+1<n && arr[i+1]==arr[i])
        {
            i++;
        }
    }

    return s2;
}
