#include<bits/stdc++.h>

using namespace std;
int K, N, M;
vector<int> DSK[1001];
vector<int> pp;
vector<int> cnt;
vector<int> vs(1001);
void input(){
	cin >> K >> N >> M;
	pp.resize(K);
	for(int i = 0; i < K; i++)
		cin >> pp[i];
	for(int i = 1; i <= N; i++){
		DSK[i].clear();
	}
	int u, v;
	
	for(int i = 1; i <= M; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
	}
	cnt.resize(N + 1, 0);
}

void DFS(int u){
	vs[u] = 1;
	cnt[u]++;
	for(auto v : DSK[u]){
		if(!vs[v]) DFS(v);	
	}
}

void solve(){
	for(auto u : pp){
		for(int i = 1; i <= N; i++)
			vs[i] = 0;
		DFS(u);
	}
	int res = 0;
	for(int i = 1; i <= N; i++){
		if(cnt[i] == K) res++;
	}	
	cout << res << endl;
}

int main() {
	input();
	solve();
	return 0;
}
