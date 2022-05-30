#include<bits/stdc++.h>

using namespace std;
int n, E, U, V; 
vector<vector<int>> DSK(1001);
vector<int> vs(1001);

void DFS(int u){
	vector<int> stk;
	stk.push_back(u);
	vs[u] = 1;
	while(!stk.empty()){
		int v = stk[stk.size() - 1];
		if(v == V) break;
		stk.pop_back();
		for(auto x : DSK[v]){
			if(!vs[x]){
				vs[x] = 1;
				stk.push_back(v);
				stk.push_back(x);
				break;
			}
		}
	}
	if(stk.empty()) cout << -1 << endl;
	else{
		for(auto it : stk)
			cout << it << " ";
		cout << endl;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> E >> U >> V;
		for(int i = 1; i <= n; i++){
			DSK[i].clear();
			vs[i] = 0;
		}
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			DSK[u].push_back(v);
		}
		DFS(U);
		
	}
	return 0;
}
