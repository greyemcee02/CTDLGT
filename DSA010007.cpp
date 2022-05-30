#include<bits/stdc++.h>

using namespace std;
int V, E, U;
vector<int> DSK[1001];
vector<int> vs(1001);
vector<pair<int,int>> res;
void input(){
	cin >> V >> E >> U;
	for(int u = 1; u <= V; u++){
		DSK[u].clear();
		vs[u] = 0;
	}
	res.clear();
	int u, v;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
	}
}

void BFS(int u){
	queue<int> Q;
	Q.push(u);
	vs[u] = 1;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		for(auto ui: DSK[v]){
			if(!vs[ui]){
				res.push_back({v, ui});
				vs[ui] = 1;
				Q.push(ui);
			}
		}
	}
}

void solve(){
	BFS(U);
	if(res.size() == V-1){
		for(auto it : res){
			cout << it.first << " " << it.second << endl;
		}
	}
	else cout << -1 << endl;
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
