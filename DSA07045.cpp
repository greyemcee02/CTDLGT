#include<bits/stdc++.h>

using namespace std;
string s;

void solve(){
	string stk1, stk2;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '<'){
			if(stk1.length()){
				stk2.push_back(stk1[stk1.length() - 1]);
				stk1.pop_back();
			}
		}
		else if(s[i] == '>'){
			if(stk2.length()){
				stk1.push_back(stk2[stk2.length() - 1]);
				stk2.pop_back();
			}
		}
		else if(s[i] == '-' ){
			if(stk1.length())
				stk1.pop_back();
		}	
		else stk1.push_back(s[i]);
	}
	while(!stk2.empty()){
		stk1.push_back(stk2[stk2.length() - 1]);
		stk2.pop_back();
	}
	cout << stk1 << endl;
}

int main() {
	cin >> s;
	solve();
	return 0;
}
