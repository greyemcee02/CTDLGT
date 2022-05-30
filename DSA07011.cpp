#include<bits/stdc++.h>

using namespace std;

string solve(string str){
	stack<string> stk;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '+' || str[i] == '-' || str[i] == '*'||str[i] =='/'){
			string s1 = stk.top();
			stk.pop();
			string s2 = stk.top();
			stk.pop();
			stk.push(str[i] + s2 + s1);
		}
		else{
			string tmp;
			tmp.push_back(str[i]);
			stk.push(tmp);
		}
	}
	return stk.top();
}

int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		cout << solve(str) << endl;
	}
	return 0;
}
