#include<bits/stdc++.h>

using namespace std;
int V, E, cl;
vector<int> DSK[1001];
vector<int> vs(1001);

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

bool DFS(int u){
	for(int i = 1; i <= cl; i++){
		bool ok = true;
		int ck = 0;
		vs[u] = i;
		for(auto v: DSK[u]){
			if(vs[v] == vs[u]){
				ok = false;
				break;
			} 
			else ck++;
		}
		if(!ok) continue;
		if(ck == DSK[u].size()) return true;
		for(auto v : DSK[u]){
			if(vs[v] == 0){
				if(DFS(v)) return true;
			} 
		}
		vs[u] = 0;
	}
	return false;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		input();
		if(DFS(1)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
