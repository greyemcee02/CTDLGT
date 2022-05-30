#include<bits/stdc++.h>

using namespace std;
int V, E;
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
	
void solve(){
	for(int u = 1; u <= V; u++){
		vs[u] = 1;
		if(u == 1) DFS(2);
		else DFS(1);
		bool check = false;
		for(int v = 1; v <= V; v++){
			if(!vs[v]) {
				check = true;
				break;
			}
		}
		if(check) cout << u << " ";
		fill(vs.begin(), vs.begin() + V + 1, 0);
		
	}
	cout << endl;
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
