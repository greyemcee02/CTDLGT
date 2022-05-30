#include<bits/stdc++.h>

using namespace std;
int V, E;
vector<int> DSK[10001];
vector<int> vs(10001);

void input() {
	cin >> V >> E;
	for(int i = 0; i <= V; i++){
		DSK[i].clear();
		vs[i] = 0;
	}	
	int u, v;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
	}
}

//void DFS(int u){
//	vs[u] = 1;
//	for(auto v : DSK[u]){
//		if(!vs[v])
//			DFS(v);
//	}
//}

int solve(){
//	int c = 0;
//	for(int i = 1; i <= V; i++){
//		if(!vs[i]){
//			DFS(i);
//			c++;
//		}
//	}
//	if(c > 1) return 0;
	int cnt = 0;
	for(int u = 1; u <= V; u++){
		if(DSK[u].size() %2 != 0)
			cnt++;
	}
	if(cnt == 0) return 2;
	if(cnt == 2) return 1;
	return 0;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		input();
		cout << solve() << endl;	
	}
	return 0;
}


