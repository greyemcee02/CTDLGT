#include<bits/stdc++.h>

using namespace std;
string str;

void solve(){
	stack<int> stk;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '(' ){
			if(i >= 1 && str[i-1] == '-'){
				stk.push(i - 1);
			}
		}
		else if(str[i] == ')'){
			if(!stk.empty()){
				int k = stk.top();
				stk.pop();
				for(int j = k + 1; j <= i - 1; j++){
					if(str[j] =='-'){
						str[j] = '+';
					}
					else if(str[j] =='+'){
						str[j] = '-';
					}
				} 
			}
		}
	}
	if(str[0] != '+' && str[0]!='(') cout << str[0];
	for(int i = 1; i < str.length(); i++){
		if(str[i] != ')' && str[i] != '(')
			cout << str[i];
	}
	cout << endl;
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
