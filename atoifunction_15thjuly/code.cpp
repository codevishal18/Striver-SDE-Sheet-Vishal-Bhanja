#include <bits/stdc++.h>
using namespace std;
 
int atoi(string str) {
    // Write your code here.
    bool sign = false;
    int start = 0;

    if(str[0] == '-'){
        sign = true;
        start = 1;
    }

    int ans=0;
    int n = str.length();
    for(int i = start ; i<n ; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            ans = ans * 10 + (str[i] - '0');
        }
    }

    if(sign == true ){
        return -ans ;
    } else {
      return ans;
    }
}