#include<bits/stdc++.h>

using namespace std;
int V, E, cl;
vector<int> DSK[100001];
vector<int> vs(100001);

void input(){
	cin >> V >> E;
	for(int u = 1; u <= V; u++){
		DSK[u].clear();
		vs[u] = 0;
	}
	int u, v;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
	}
}

void DFS(int u, int &cnt){
	cnt++;
	vs[u] = 1;
	for(auto v : DSK[u]){
		if(!vs[v]) DFS(v, cnt);
	}
}

void solve(){
	int res = 0;
	int daduyet = 0;
	for(int u = 1; u <= V; u++){
		if(!vs[u]){
			int cnt = 0;
			DFS(u, cnt);
			daduyet += cnt;
			res = max(res, cnt);
			if(res >= V - daduyet) break;
		}
	}
	cout << res << endl;
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
