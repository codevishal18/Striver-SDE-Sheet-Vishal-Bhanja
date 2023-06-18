#include<bits/stdc++.h>
using namespace std;

string reverseString(string &str){
	// Write your code here.
	stack<string> st;
	string s;
	for(int i=0;i<str.size();i++){
		if(s.empty()&&str[i]==' ')continue;
		else if(str[i]==' '){
			st.push(s);
			s.erase();
		}
		else {
			s.push_back(str[i]);
		}
	}

	if(!s.empty())st.push(s);

	string p="";

	while(!st.empty()){

	p+=st.top();

	p+=" ";

	st.pop();

	}

return p;	
}