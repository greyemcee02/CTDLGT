#include<bits/stdc++.h>

using namespace std;
int n, m;
int res;
vector<int> x;
int MT[21][21];

void DFS(int i, int cnt){
	res = max(res, cnt);
	for(int j = 0; j < 21; j++){
		if(MT[i][j]){
			MT[i][j] = 0;
			MT[j][i] = 0;
			DFS(j, cnt + 1);
			MT[i][j] = 1;
			MT[j][i] = 1;
		}
	}
}


int main() {
	int test;
	cin >> test;
	while(test--){
		res = 0;
		int u, v;
		cin >> n >> m;
		for(int i = 0; i < 21; i++)
			for(int j = 0; j < 21; j++)
				MT[i][j] = 0;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			MT[u][v] = 1;
			MT[v][u] = 1;
		}
		for(int i = 0; i < 21; i++){
			DFS(i, 0);
		}
		cout << res << endl;
	}	
	return 0;
}
