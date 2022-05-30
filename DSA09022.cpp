#include<bits/stdc++.h>

using namespace std;
int V, E, U;
vector<vector<int>> DSK(1001);
vector<int> vs(1001);

void DFS(int u){
	vs[u] = 1;
	cout << u << " ";
	for(auto v : DSK[u]){
		if(!vs[v]){
			DFS(v);
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> V >> E >> U;
		for(int i = 0; i <= V; i++){
			DSK[i].clear();
			vs[i] = 0;
		}
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			DSK[u].push_back(v);
		}
		DFS(U);
		cout << endl;
	}
	
	return 0;
}
