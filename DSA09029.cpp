#include<bits/stdc++.h>

using namespace std;
int V, E;
vector<int> DSK[11];
vector<int> vs(11);
int ok;
void input(){
	cin >> V >> E;
	for(int i = 1; i <= V;i++){
		vs[i] = 0;
		DSK[i].clear();
	}
	int u, v;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
	}
	ok = 0;
}

void DFS(int u, int cnt){
	if(ok) return;
	vs[u] = 1;
	if(cnt == V){
		ok = 1;
		return;
	}
	for(auto v : DSK[u]){
		if(!vs[v]){
			DFS(v, cnt + 1);
		}
	}
	vs[u] = 0;
}

void solve(){
	input();
	for(int i = 1; i <= V; i++){
		if(ok) break;
		DFS(i, 1);
	}
	cout << ok << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		solve();		
	}
	return 0;
}
