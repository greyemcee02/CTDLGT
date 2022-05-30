#include<bits/stdc++.h>

using namespace std;
int N, E;
vector<vector<int>> DSK(1001);
vector<int> vs(1001);

int BFS(int u, int v){
	queue<int> Q;
	Q.push(u);
	vs[u] = 1;
	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		if(x == v) return 1;
		for(auto v1 : DSK[x]){
			if(!vs[v1]){
				vs[v1] = 1;
				Q.push(v1);
			}
		} 
	}
	return 0;
}

int main(){
	int test;
	cin >> test;
	while(test--){
		cin >> N >> E;
		for(int i = 0; i <= N; i++){
			DSK[i].clear();
		}
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			DSK[u].push_back(v);
			DSK[v].push_back(u);			
		}
		int q;
		cin >> q;
		while(q--){
			for(int i = 0; i <= N; i++)
				vs[i] = 0;
			cin >> u >> v;
			cout << (BFS(u, v)?"YES":"NO") << endl;
		}
	} 
	return 0;
}
