#include<bits/stdc++.h>

using namespace std;
int V, E, st;
vector<int> vs(1001);
vector<pair<int, int>> DSK[1001];
vector<int> D(1001);

void input(){
	cin >> V >> E >> st;
	for(int u = 1; u <= V; u++){
		vs[u] = 0;
		D[u] = INT_MAX;
		DSK[u].clear();
	}
	int u, v, w;
	for(int i = 1; i <= E; i++){
		cin >> u >> v >> w;
		DSK[u].push_back({v,w});
		DSK[v].push_back({u,w});
	}
}

void Dijkstra(int st){
	for(auto u : DSK[st]){
		D[u.first] = u.second;
	}
	D[st] = 0;
	vs[st] = 1;
	while(1){
		int mn = INT_MAX;
		int u = 0;
		for(int v = 1; v <= V; v++){
			if(!vs[v] && mn > D[v]){
				mn = D[v];
				u = v;
			}
		}
		if(u == 0) break;
		vs[u] = 1;
		for(auto v : DSK[u]){
			if(D[v.first] > D[u] + v.second)
				D[v.first] = D[u] + v.second;
		}
	}
	for(int u = 1; u <= V; u++)
		cout << D[u] << " ";
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		input();
		Dijkstra(st);
	}
	return 0;
}
