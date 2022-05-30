#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> child[200001];
vector<int> DD(200001);


void input(){
	cin >> n;
	int u;
	for(int i = 1; i <= n; i++){
		DD[i] = 1;
		child[i].clear();
	}
	for(int i = 2; i <= n; i++){
		cin >> u;
		child[u].push_back(i);
	}
}

void DFS(int u){
	for(auto v : child[u]){
		DFS(v);
		DD[u] += DD[v] + 1;
	}
}

void solve(){
	DFS(1);
	for(int u = 1; u <= n; u++)
		cout << DD[u] << " ";
	cout << endl;
}
int main() {
	input();
	solve();
	return 0;
}
