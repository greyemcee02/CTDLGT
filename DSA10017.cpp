#include<bits/stdc++.h>

using namespace std;
int V, E;
vector<pair<int, int>> DSK[1001];
vector<int> D(1001), pr(1001);
bool res;
void input(){
	cin >> V >> E;
	for(int i = 1; i <= V; i++){
		DSK[i].clear();
		D[i] = INT_MAX;
		pr[i] = INT_MAX;
	}
	int u, v, w;
	for(int i = 1; i <= E; i++){
		cin >> u >> v >> w;
		DSK[u].push_back({v, w});
	}
	res = false;
}

bool bellman_ford(){
	for(int u = 1; u <= V; u++){
		D[u] = INT_MAX;
		pr[u] = 0;
	}
	pr[1] = 0;
	D[1] = 0;
	for(int cnt = 1; cnt <= V-1; cnt++){
		for(int u = 1; u <= V; u++){
			for(auto v : DSK[u]){
				if(D[v.first] > D[u] + v.second ){
					D[v.first] = D[u] + v.second;
					pr[v.first] = u;
				}
			}
		}
	}
	for(int u = 1; u <= V; u++){
		for(auto v : DSK[u]){
			if(D[v.first] > D[u] + v.second ){
				D[v.first] = D[u] + v.second;
				pr[v.first] = u;
				return true;
			}
		}
	}
	return false;
}



int main() {
	int test;
	cin >> test;
	while(test--) {
		input();
		cout << bellman_ford() << endl;
	}	
	return 0;
}
