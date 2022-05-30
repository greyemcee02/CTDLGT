#include<bits/stdc++.h>

using namespace std;
vector<int> vs(1001);
vector<int> DSK[1001];
int N, M;
bool ok;
void input(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		vs[i] = 0;
		DSK[i].clear();
	}
	int u, v;
	for(int i = 1; i <= M; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
	}
	ok = true;
}

void BFS(int u, int color){
	vs[u] = color;
	queue<pair<int, int>> Q;
	Q.push({u, color});
	while(!Q.empty()){
		pair<int, int> pr = Q.front();
		Q.pop();
		for(auto v : DSK[pr.first]){
			if(vs[v] == 0){
				Q.push({v, 3-pr.second});
				vs[v] = 3 - pr.second;
			}
			else if(vs[v] == pr.second){
				ok = false;
				return;
			}
		}
	}
}

void solve(){
	for(int u = 1; u <= N; u++){
		if(!vs[u]){
			BFS(u, 1);
		}
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		input();
		solve();
	}
	return 0;
}
