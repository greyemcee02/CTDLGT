#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		stack<int> stk;
		stk.push(-1);
		int res = 0;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == ')'){
				int k = stk.top();
				if(k > -1 && str[k] == '('){
					stk.pop();
					res = max(res, i - stk.top());
				}
				else stk.push(i);
			}
			else
				stk.push(i);
		}
		cout << res << endl;
	}
	return 0;
}
