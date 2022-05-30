#include<bits/stdc++.h>

using namespace std;
vector<int> DSK[100001];
vector<int> height(100001);

void DFS(int u){
	for(auto it : DSK[u]){
		DFS(it);
		height[u] = max(height[u], height[it] + 1);
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			DSK[i].clear();
			height[i] = 0;
		}
		int u, v;
		for(int i = 1; i < n; i++){
			cin >> u >> v;
			DSK[u].push_back(v);
		}		
		DFS(1);
		cout << height[1] << endl;
	}
	return 0;
}
