#include<bits/stdc++.h>

using namespace std;
int V, E, k;
vector<int> DSK[1005];

void input(){
	cin >> V >> E >> k;
	for(int u = 1; u <= V; u++ ){
		DSK[u].clear();
	}	
	int u, v;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
		DSK[v].push_back(u);
	}
}

void solve(){
	vector<int> res(V + 1, -1);
	vector<int> color(V + 1, -1);
	priority_queue<pair<int, int>> pq;
	for(int u = 1; u <= V; u++){
		pq.push({DSK[u].size(), u});
	}
	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for(auto v : DSK[u]){
			if(res[v] != -1){
				color[res[v]] = 1;
			}
		}
		for(int i = 1; i <= V; i++){
			if(color[i] == -1){
				res[u] = i;
				break;
			}
		}
		for(auto v : DSK[u]){
			if(res[v] != -1){
				color[res[v]] = -1;
			}
		}	
	}
	bool ok = true;
	for(int i = 1; i <= V; i++){
		if(res[i] == -1 || res[i] > k){
			ok = false;
			break;
		}
		//cout << i << " " << res[i] << endl;
	}
	if(ok)
	cout << "YES" << endl;
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
