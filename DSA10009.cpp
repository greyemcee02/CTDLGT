#include<bits/stdc++.h>

using namespace std;
int N, M;
int D[102][102];

void FLOYD(){
	for(int k = 1; k <= N; k++){
		for(int u = 1; u <= N; u++){
			for(int v = 1; v <= N; v++){
				if(D[u][v] > D[u][k] + D[k][v])
					D[u][v] = D[u][k] + D[k][v];
			}
		}
	}
	
}

int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(i == j) D[i][j] = 0;
			else D[i][j] = 1e9;
		}
	}
	int u, v, w;
	for(int i = 1; i <= M; i++){
		cin >> u >> v >> w;
		D[u][v] = w;
		D[v][u] = w;
	}
	FLOYD();
	int Q;
	cin >> Q;
	while(Q--){
		cin >> u >> v;
		cout << D[u][v] << endl;
	}
	return 0;
}
