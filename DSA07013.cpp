#include<bits/stdc++.h>

using namespace std;

int solve(int b, char pt, int a){
	if(pt == '+') return b+a;
	if(pt == '-') return b-a;
	if(pt == '*') return b*a;
	return b/a;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		stack<int> stk;
		for(int i = 0; i < str.length(); i++){
			if(isdigit(str[i])){
				stk.push(str[i]-'0');
			}
			else{
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();
				stk.push(solve(b, str[i], a));
			}
		}
		cout << stk.top() << endl;
	}
	return 0;
}
