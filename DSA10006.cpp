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

void DFS(int u, int pr){
	vs[u] = 1;
	if(pr!=0)
	res.push_back({pr, u});
	for(auto v : DSK[u]){
		if(!vs[v]) DFS(v, u);
	}
}

void solve(){
	DFS(U, 0);
	bool ok = true;
	for(int u = 1; u <= V; u++){
		if(!vs[u]){
			ok = false;
			break;
		}
	}
	if(ok){
		for(auto it : res)
			cout << it.first << " " << it.second << endl;
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
