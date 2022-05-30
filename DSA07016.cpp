#include<bits/stdc++.h>

using namespace std;
string str;

void solve(){
	stack<char> stk;
	stk.push('1');
	string res;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 'D'){
			stk.push( ('0' + i + 2));
		}
		else{
			while(!stk.empty()){
				res.push_back(stk.top());
				stk.pop();
			}
			stk.push(('0' + i + 2));
		}
	}
	while(!stk.empty()){
		res.push_back(stk.top());
		stk.pop();
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
