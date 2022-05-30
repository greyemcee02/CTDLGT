#include<bits/stdc++.h>

using namespace std;
int V, E;

void BFS(vector<vector<int>> &DSK, vector<int> &vs, int u){
	queue<int> Q;
	Q.push(u);
	vs[u] = 1;
	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		for(auto v : DSK[x]){
			if(!vs[v]){
				vs[v] = 1;
				Q.push(v);
			}
		}
	}
}

void solve(vector<vector<int>> &DSK){
	
	for(int i = 1; i <= V; i++){
		vector<int> vs(V+1, 0);
		vs[i] = 1;
		int cnt = 0;
		for(int j = 1; j <= V; j++){
			if(vs[j] == 0){
				cnt++;
				BFS(DSK, vs, j);
			}
		}
		if(cnt > 1) cout << i << " ";
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> V >> E;
		vector<vector<int>> DSK(V + 1);
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			DSK[u].push_back(v);
			DSK[v].push_back(u);
		}
		solve(DSK);	
	}	
	return 0;
}
