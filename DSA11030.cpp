#include<bits/stdc++.h>

using namespace std;
vector<int> DSK[1001];
vector<int> vs(1001);
int n, res;
bool ok;
void input(){
	cin >> n;
	int u, v;
	res = 0;
	for(int i = 1; i <= n; i++){
		DSK[i].clear();
		vs[i] = 0;
	}
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
	}
}

void DFS(int u, int v){
	vs[u] = 1;
	if(vs[v]){
		return;
	}
	res++;
	for(auto it : DSK[u]){
		if(!vs[it] && !vs[v]){
			DFS(it, v);
		}
	}
	if(!vs[v]) res--;
}

void solve(){
	int q;
	cin >> q;
	while(q--){
		for(int i = 1; i <= n; i++)
			vs[i] = 0;
		int u, v;
		cin >> u >> v;
		DFS(u, v);
		cout << res << endl;
		res = 0;
	}
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


