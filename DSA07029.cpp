#include<bits/stdc++.h>

using namespace std;
string str;

void solve(){
	stack<string> stk;
	string s = "";
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '['){
			if(stk.empty() || !isdigit(stk.top()[0])){
				stk.push("1");
			}
			stk.push("[");
		}
		else if(isdigit(str[i])){
			if(stk.empty() || !isdigit(stk.top()[0])){
				stk.push(s + str[i]);
			}
			else
				stk.top().push_back(str[i]);
		}
		else if(isalpha(str[i])){
			if(stk.empty() || !isalpha(stk.top()[0])){
				stk.push(s + str[i]);
			}
			else
				stk.top().push_back(str[i]);
		}
		else{
			string tmp = stk.top();
			stk.pop();
			stk.pop();
			int x;
			string nb = stk.top();
			stk.pop();
			istringstream is(nb);
			is >> x;
			string tp = "";
			while(x--){
				tp += tmp;
			}
			if(stk.empty() || !isalpha(stk.top()[0])){
				stk.push(tp);
			}	
			else{
				string tm = stk.top();
				stk.pop();
				stk.push(tm + tp);
			}
		}
	}
	while(!stk.empty()){
		s = stk.top() + s;
		stk.pop();
	}
	cout << s << endl;
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
