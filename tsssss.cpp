#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
	unordered_set<int> st;
	queue<pair<int, int>> Q;
	Q.push({n, 0});
	int res = INT_MAX;
	while(res == INT_MAX && !Q.empty()){
		pair<int, int> k = Q.front();
		Q.pop();
		if(st.find(k.first - 1) == st.end()){
			Q.push({k.first - 1, k.second + 1});
			if(k.first - 1 == 1){
				res = k.second + 1;
				break;
			}
			st.insert(k.first - 1);
		}
		for(int i = k.first - 1; i >= sqrt(k.first); i--){
			if(k.first % i == 0 ){
				int sz = st.size();
			//	Q.push({i, k.second + 1});
				st.insert(i);
				if(st.size() > sz){
					Q.push({i, k.second + 1});
					if(i == 1){
						res = k.second + 1;
						break;
					}
				}
				
			}
		}
	}
	cout << res << endl;
}
int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		solve();
	}
	return 0;
}
