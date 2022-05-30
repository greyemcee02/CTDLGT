#include<bits/stdc++.h>

using namespace std;
int V, E;
vector<int> DSK[10005];
vector<int> vs(10005);
void input() {
	cin >> V >> E;
	for(int u = 1; u <= V; u++){
		DSK[u].clear();
		vs[u] = 0;
	}
	int u, v;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
	}
	for(int i = 1; i <= V; i++){
		sort(DSK[i].begin(), DSK[i].end());
	}
}

void DFS(int u){
	stack<pair<int, int>> stk;
	stk.push({u, 0});
	vs[u] = 1;
	bool ok = false;
	while(!stk.empty()){
		pair<int, int> pir = stk.top(); 
		stk.pop();
		int v = pir.first;
		int pr = pir.second;
		for(auto ui : DSK[v]){
			if(ui == 1 && ui != pr){
				stk.push({v, pr});
				stk.push({ui, v});
				ok = true;
				break;
			}
			else if(!vs[ui]){
				vs[ui] = 1;
				stk.push({v, pr});
				stk.push({ui, v});
				break;
			}
		}
		if(ok) break;
	}
	if(ok){
		vector<int> res(stk.size());
		for(int i = res.size() - 1; i>= 0; i--){
			res[i] = stk.top().first;
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
		DFS(1);
	}
	return 0;
}
//1
//4 4
//1 2 1 3 3 4 4 1

