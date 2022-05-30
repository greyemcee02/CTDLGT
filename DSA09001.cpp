#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		int V, E, u, v;
		cin >> V >> E;
		vector<vector<int>> DSK(V + 1);
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			DSK[u].push_back(v);
			DSK[v].push_back(u);
		}
		for(int i = 1; i <= V; i++){
			cout << i << ": ";
			for(auto it : DSK[i])
				cout << it << " ";
			cout << endl;
		}
	}
	return 0;
}
