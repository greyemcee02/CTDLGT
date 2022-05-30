#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> G(1001), TG(1001);
int V, E;
vector<int> vs(1001);
stack<int> stk;

void DFS1(int u){
	vs[u] = 1;
	for(int v = 0; v < G[u].size(); v++){
		if(!vs[G[u][v]]){
			DFS1(G[u][v]);
		}
	}
	stk.push(u);
}

void DFS2(int u){
	vs[u] = 1;
	for(int v = 0; v < TG[u].size(); v++){
		if(!vs[TG[u][v]]){
			DFS2(TG[u][v]);
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> V >> E;
		for(int i = 0; i <= V; i++ ){
			G[i].clear();
			TG[i].clear();
			vs[i] = 0;
		}
		//while(!stk.empty())
		//	stk.pop();
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			G[u].push_back(v);
			TG[v].push_back(u);
		}
		for(int i = 1; i <= V; i++){
			if(!vs[i]){
				DFS1(i);
			}
		}
		int cnt = 0;
		for(int i = 1; i <= V; i++)
			vs[i] = 0;
		while(!stk.empty()){
			int u = stk.top();
			stk.pop();
			if(!vs[u]){
				cnt++;
				vs[u] = 1;
				DFS2(u);
			}
		}
		if(cnt == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
