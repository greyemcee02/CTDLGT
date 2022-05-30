#include<bits/stdc++.h>

using namespace std;
string str;

void solve(){
	stack<string> stk;
	string s;
	for(int i = 0; i < str.length(); i++){
		if(isalpha(str[i]))
			stk.push(s + str[i]);
		else{
			string s1 = stk.top();
			stk.pop();
			string s2 = stk.top();
			stk.pop();
			stk.push('(' + s2 + str[i] + s1 + ')');
		}
	}
	cout << stk.top() << endl;
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
