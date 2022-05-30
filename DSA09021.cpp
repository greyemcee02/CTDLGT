#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, tmp;
	cin >> n;
	vector<vector<int>> MTK(n+1);
	for(int u = 1; u <= n; u++){
		for(int v = 1; v <= n; v++){
			cin >> tmp;
			if(tmp){
				MTK[u].push_back(v);
			}
		}
	}
	for(int u = 1; u <= n; u++){
		for(auto v : MTK[u]){
			cout << v << " ";
		}
		cout << endl;
	}
	return 0;
}
