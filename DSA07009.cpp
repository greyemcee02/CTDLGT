#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		stack<char> stk;
		stack<string> res;
		for(int i = 0; i < str.length(); i++){
			stk.push(str[i]);
		}
		while(!stk.empty()){
			char a = stk.top();
			stk.pop();
			if(isalpha(a)){
				string s;
				s.push_back(a);
				res.push(s);
			}
			else{
				string s1 = res.top();
				res.pop();
				string s2 = res.top();
				res.pop();
				s1 = "(" + s1 + a + s2 + ")";
				res.push(s1);
			}
		}
		cout << res.top() << endl;
	}
	return 0;
}
