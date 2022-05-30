#include<bits/stdc++.h>

using namespace std;
int V, E;
bool ok;
vector<int> DSK[10001];
vector<int> vs(10001);

void input() {
	cin >> V >> E;
	ok = false;
	for(int i = 0; i <= V; i++){
		DSK[i].clear();
		vs[i] = 0;
	}	
	int u, v;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
	}
}

void DFS(int u, int pr){
	if(ok) return;
	vs[u] = 1;
	for(auto v : DSK[u]){
		if(vs[v] && v!=pr){
			ok = true;
			return;
		}
		else if(!vs[v])
			DFS(v, u);
	}
	vs[u] = 0;
}

void solve(){
	for(int v = 1; v <= V; v++){
		if(!vs[v]){
			DFS(v, 0);
			if(ok) break;
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

//1
//6 6
//1 2 3 4 2 4 4 5 5 6 5 3


