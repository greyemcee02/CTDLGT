#include<bits/stdc++.h>

using namespace std;
int V;
vector<int> DSK[1005];
vector<int> vs(1005);

void DFS(int u){
	vs[u] = 1;
	for(auto v : DSK[u]){
		if(!vs[v])
			DFS(v);
	}
}

void input() {
	cin >> V;
	for(int u = 1; u <= V; u++){
		DSK[u].clear();	
		vs[u] = 0;
	}
	int u, v;
	for(int i = 1; i <= V-1; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
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
	while(test--) {
		input();
		solve();
	}
	return 0;
}
