#include<bits/stdc++.h>

using namespace std;
int V, E;
vector<int> DSK[10005];
vector<int> vs(10005);
stack<int> stk;
bool ok;
void input() {
	cin >> V >> E;
	for(int u = 1; u <= V; u++){
		DSK[u].clear();
		vs[u] = 0;
	}
	int u, v;
	while(!stk.empty()) stk.pop();
	ok = false;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
	}
	for(int i = 1; i <= E; i++){
		sort(DSK[i].begin(), DSK[i].end());
	}
}

void DFS(int u, int pr){
	if(ok) return;
	vs[u] = 1;
	stk.push(u);
	for(auto v : DSK[u]){
		if(ok) return;
		if(vs[v] == 1 &&v!=pr){
			stk.push(v);
			//vs[v] = 1;
			ok = true;
			return;
		}
		else if(!vs[v]){
			DFS(v, u);
		//	stk.pop();
		}
	}
	if(!ok)
	stk.pop();
}

void solve(){
	DFS(1, 0);
	if(ok){
		vector<int> res(stk.size());
		for(int i = stk.size() - 1; i >= 0; i--){
			res[i] = stk.top();
			stk.pop();
		}
		for(auto it : res)
			cout << it << " ";
		cout << endl;
	}
	else cout << "NO" << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		input();
		solve();
	}
	return 0;
}
//1
//6 6
//1 2 2 3 3 6 3 5 4 2 2 5
