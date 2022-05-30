#include<bits/stdc++.h>

using namespace std;
int V, E, U;
vector<vector<int>> DSK(1001);
vector<int> vs(1001);

void BFS(int u){
	queue<int> Q;
	Q.push(u);
	vs[u] = 1;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		cout << v << " ";
		for(auto it : DSK[v]){
			if(!vs[it]){
				Q.push(it);
				vs[it] = 1;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> V >> E >> U;
		for(int i = 0; i <= V; i++){
			vs[i] = 0;
			DSK[i].clear();
		}
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			DSK[u].push_back(v);
			DSK[v].push_back(u);
		}
		BFS(U);
		cout << endl;
	}
	return 0;
}
