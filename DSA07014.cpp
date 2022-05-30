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
		stack<char> stk;
		for(int i = 0; i < str.length(); i++){
			stk.push(str[i]);
		}
		stack<int> res;
		while(!stk.empty()){
			char c = stk.top();
			stk.pop();
			if(isdigit(c)){
				res.push(c - '0');
			}
			else{
				int a = res.top();
				res.pop();
				int b = res.top();
				res.pop();
				res.push(solve(a, c, b));
			}
		}
		cout << res.top() << endl;
	}
	return 0;
}
