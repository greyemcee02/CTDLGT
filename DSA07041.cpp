#include<bits/stdc++.h>

using namespace std;
string str;

void solve(){
	stack<char> stk;
	int res = 0;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '(')
			stk.push(str[i]);
		else{
			if(!stk.empty()){
				res += 2;
				stk.pop();
			}
		}
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
