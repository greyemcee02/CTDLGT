#include<bits/stdc++.h>

using namespace std;
string str;
set<string> st;
void solve(){
	stack<int> stk;
	for(int i = 0; i < str.length(); i++){
		if(str[i] =='('){
			stk.push(i);
		} 
	}
	vector<int> check(str.length(), 1);
	while(!stk.empty()){
		int k = stk.top();
		stk.pop();
		int cnt = 0;
		check[k] = 0;
		string s;
		int k1;
		for(int i = k + 1; i < str.length(); i++){
			if(str[i] == '('){
				stk.push(i);
				check[i] = 1;
				cnt++;
			}
			else if(str[i] == ')'){
				if(cnt == 0 ){
					check[i] = 0;
					k1 = i + 1;
					break;
				}		
				cnt--;
				check[i] = 1;	
			}
		}		
		cnt = 0;
		for(int j = k1; j < check.size(); j++){
			if(str[j] == '('){
				stk.push(j);
				cnt++;
				check[j] = 1;
			}
			else if(str[j] == ')'){
				if(cnt > 0){
					check[j] = 1;
					cnt--;
				}
				else
					break;
			}
		}
		for(int i = 0; i < check.size(); i++)
			if(check[i]) s.push_back(str[i]);
		st.insert(s);
		//cout << s << endl;
	}
	for(auto it : st)
		cout << it << endl;
}

int main() {
//	int test;
//	cin >> test;
//	while(test--){
		getline(cin, str);
		solve();
//	}
	return 0;
}
