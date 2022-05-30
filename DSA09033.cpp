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

void DFS(int u){
	vs[u] = 1;
	for(auto v : DSK[u]){
		if(!vs[v]) DFS(v);
	}
}

void solve(){
	DFS(1);
	bool ok = true;
	for(int u = 1; u <= V; u++){
		if(!vs[u]){
			ok = false;
			break;
		}
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
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
