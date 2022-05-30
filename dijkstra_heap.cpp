#include<bits/stdc++.h>

using namespace std;
int V, E;
vector<pair<int, int>> DSK[1001];
vector<int> vs(1001);
vector<int> D(1001);
int st;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
void input(){
	cin >> V >> E >> st;
	for(int i = 1; i <= V; i++){
		DSK[i].clear();
		vs[i] = 0;
		D[i] = 1e9;
	}
	while(!Q.empty())
		Q.pop();
	int u, v, w;
	for(int i = 1; i <= E; i++){
		cin >> u >> v >> w;
		DSK[u].push_back({w, v});
		DSK[v].push_back({w, u});
	}
}

void Dijkstra(int st){
	while(!Q.empty()) Q.pop();
	Q.push({0, st});
	D[st] = 0;
	while(!Q.empty()){
		pair<int, int> pr = Q.top();
		Q.pop();
		for(auto v : DSK[pr.second]){
			if( D[v.second] > D[pr.second] + v.first){
				D[v.second] = D[pr.second] + v.first;
				Q.push({D[v.second], v.second});
			}
		}
	}
	for(int i = 1; i <= V; i++)
		cout << D[i] << " ";
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
