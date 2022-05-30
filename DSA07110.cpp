#include<bits/stdc++.h>

using namespace std;

bool check(char a, char b){
	if(a == '(' && b == ')') return true;
	if(a == '[' && b == ']') return true;
	if(a == '{' && b == '}') return true;
	return false;
}

string solve(string str){
	stack<char> stk;
	for(auto it : str){
		if(it == '(' || it == '[' || it == '{')
			stk.push(it);
		else{
			if(!stk.empty() && check(stk.top(), it)){
				stk.pop();
			}
			else return "NO";
		}
	}
	return "YES";
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
