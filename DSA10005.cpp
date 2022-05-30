#include<bits/stdc++.h>

using namespace std;
int V, E;
vector<int> vs(10001);
vector<int> degS(1005), degA(1005);
void input() {
	cin >> V >> E;
	for(int v = 1; v <= V; v++){
		degS[v] = 0;
		degA[v] = 0;
	}
	int u, v;
	for(int i = 1; i <= E; i++){
		cin >> u >> v;
		degA[u]++;
		degS[v]++;
	}
}

int solve(){
	for(int u = 1; u <= V; u++){
		if(degS[u] - degA[u] != 0)
			return 0;
	}
	return 1;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		input();
		cout << solve() << endl;	
	}
	return 0;
}


