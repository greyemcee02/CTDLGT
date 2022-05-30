#include<bits/stdc++.h>

using namespace std;
string str;
int gt(char c){
	if(c == '-' || c == '+') return 1;
	if(c == '*' || c == '/' ) return 2;
	if(c == '^') return 3;
	return -1;
}

bool ck(char c){
	if(c == '+' || c =='-' || c=='*'|| c== '/' || c == '^') return true;
	return false;
}
void solve(){
	stack<char> stk1; 
	string res;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			stk1.push(str[i]);
		}
		else if(isalpha(str[i])) res.push_back(str[i]);	
		else if(str[i] == ')'){
			while(!stk1.empty() && stk1.top() != '('){
				res.push_back(stk1.top());
				stk1.pop();
			}
			if(!stk1.empty() && stk1.top() == '('){
				stk1.pop();
			}
		}
		else if(ck(str[i])){
			while(!stk1.empty() && gt(str[i]) <= gt(stk1.top())){
				res.push_back(stk1.top());
				stk1.pop();
			}
			stk1.push(str[i]);
		}
	}
	while(!stk1.empty()){
		if(stk1.top() != '(')
			res.push_back(stk1.top());
		stk1.pop();
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> str;
		solve();
	}
	return 0;
}
