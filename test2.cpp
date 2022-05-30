#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	ifstream ifs;
	ifs.open("DSC.in");
	
	ifs >> n >> m;
	int mtk[n + 1][n + 1] = {0};
	for(int i = 0; i < m; i++){
		int u, v;
		ifs >> u >> v;
		mtk[u][v] = 1;
		mtk[v][u] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1;j <= n; j++)
			cout << mtk[i][j] << " ";
		cout << endl;
	}
	return 0;
}
