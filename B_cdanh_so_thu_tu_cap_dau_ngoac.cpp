#include<bits/stdc++.h>

using namespace std;
string str;

void solve(){
	stack<char> stk;
	int cnt = 0;
	vector<int> res;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			cnt++;
			stk.push(cnt);
			res.push_back(cnt);
		}
		else if(str[i] == ')'){
			res.push_back(stk.top());
			stk.pop();
		}
	}
	for(auto it : res)
		cout << it << " ";
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	cin.ignore();
	while(test--){
		getline(cin, str);
		solve();
	}	
	return 0;
}
