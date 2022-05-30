#include<bits/stdc++.h>

using namespace std;

int solve(string str){
	stack<char> stk;
	int res = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '(') stk.push('(');
		else{
			if(stk.empty()){
				res++;
				stk.push('(');
			}
			else stk.pop();
		}
	}
	if(!stk.empty()){
		res += stk.size()/2;
	}
	return res;
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
