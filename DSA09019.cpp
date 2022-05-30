#include<bits/stdc++.h>

using namespace std;
int V, E;
vector<int> DSK[1005];
vector<int> vs(1005);
bool ok;


void DFS(int u, int pr){
	if(ok) return;
	vs[u] = 1;
	for(auto v : DSK[u]){
		if(ok) return;
		if(!vs[v]) DFS(v, u);
		else if(v != pr){
			ok = true;
			return;
		}
	}
}

void solve(){
	ok = false;
	for(int u = 1; u <= V; u++){
		if(ok) break;
		if(!vs[u]) DFS(u, 0);
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> V >> E;
		for(int v = 1; v <= V; v++){
			DSK[v].clear();
			vs[v] = 0;
		}
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			DSK[v].push_back(u);
			DSK[u].push_back(v);
		}
		solve();
	}
	return 0;
}
//1
//5 4
//1 2 3 4 4 5 3 5
