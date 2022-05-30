#include<bits/stdc++.h>

using namespace std;
int n;
void solve(){
//	int check[100000] ={INT_MAX};
	queue<pair<int, int>> Q;
	Q.push({n, 0});
	set<int> st;
	st.insert(n);
	int res = INT_MAX;
	while(res == INT_MAX && !Q.empty()){
		pair<int, int> k = Q.front();
		Q.pop();
		if(k.first == 1){
			res = k.second;
			break;
		}
		if(st.find(k.first - 1) == st.end()){
			Q.push({k.first - 1, k.second + 1});
			st.insert(k.first - 1);
		}
		for(int i = sqrt(k.first); i >= 2 ; i--){
			if(k.first % i == 0 && k.first/i != 1){
				if(st.find(k.first/i) == st.end()){
					Q.push({k.first/i, k.second + 1});
					st.insert(k.first/i);
				//	break;
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
