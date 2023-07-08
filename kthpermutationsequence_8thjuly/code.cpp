#include<bits/stdc++.h>
using namespace std;

string kthPermutation(int n, int k) {
    // Write your code here.
    int fact = 1;
        vector<int> nums;
        for(int i=1;i<n;i++)
        {
            fact = fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);  
        //we store the first permutation in an array and reduce k by 1
        //for a particular n say 4 perm starting with 1,2,3,4 will have 6 perm each as total perm = 4! and each will have 24/4=6
        //so we store that in fact = 6

        string ans = "";
        k=k-1;
        while(true)
        {
            ans += to_string(nums[k/fact]);  //we find out the starting element of the required permutation by doing k/fact
            nums.erase(nums.begin()+k/fact); //we remove the staring element of the perm from the array

            if(nums.size()==0)
            {
                break;
            }

            k %= fact;  //rem after dividing by fact will be the required perm starting with recently added element
            fact /= nums.size(); //now for 4 elements firstly they had 6 perm each now for each starting element they will have 2 each
        }

        return ans;
}
