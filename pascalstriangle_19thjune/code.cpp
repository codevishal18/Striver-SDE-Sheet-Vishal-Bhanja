#include <bits/stdc++.h> 
using namespace std;
 

vector<long long int> level(vector<long long int> prev) {

  vector<long long int> temp;

  temp.push_back(1);

  for(int i=1; i<prev.size(); i++) {

    long long int t = prev[i-1]+prev[i];

    temp.push_back(t);

  }

  temp.push_back(1);

  return temp;

}

 

vector<vector<long long int>> printPascal(int n) 

{

  vector<vector<long long int>> ans;

  vector<long long int> a;

  a.push_back(1);

  ans.push_back(a);

  n--;

  int cnt = 0;

 

  while(n--) {

    ans.push_back(level(ans[cnt++]));

  }

 

  return ans;

}