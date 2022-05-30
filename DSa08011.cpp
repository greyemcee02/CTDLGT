#include<bits/stdc++.h>

using namespace std;
set<string> st;
int n;
string start, ed;
void input(){
	cin >> n >> start >> ed;
	string str;
	st.clear();
	for(int i = 1; i <= n; i++){
		cin >> str;
		st.insert(str);
	}
}

bool check(string s1, string s2){
	int cnt = 0;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i]!= s2[i]) cnt++;
		if(cnt > 1) return false;
	}
	return cnt;
}

void solve(){
	if(start == ed){
		cout << 1 << endl;
		return;
	}
	st.erase(start);
	queue<pair<int, string>> Q; 
	Q.push({1, start});
	while(!Q.empty()){
		string s = Q.front().second;
		int b = Q.front().first;
		Q.pop();
		for(auto it = st.cbegin(); it != st.cend(); ){
			if(check(*it, s)){
				if(*it == ed){
					cout << b + 1 << endl;
					return;
				}
				Q.push({b + 1, *it});
				st.erase(it++);
			}
			else it++;
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		input();
		solve();	
	}
	return 0;
}
