#include<bits/stdc++.h>

using namespace std;
int n, E, U, V; 
vector<vector<int>> DSK(1001);
vector<int> vs(1001);

void BFS(int u){
	queue<int> Q;
	Q.push(u);
	vs[u] = 1;
	vector<int> check(n + 1, 0);
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		if(v == V){
			break;
		}
		for(auto it : DSK[v]){
			if(!vs[it]){
				vs[it] = 1;
				check[it] = v;
				Q.push(it);
			}
		}
	}
	if(Q.empty()) cout << -1 << endl;
	else{
		stack<int> res;
		int v = V;
		res.push(v);
		while(check[v] != u){
			res.push(check[v]);
			v = check[v];
		}
		res.push(u);
		while(!res.empty()){
			cout << res.top() << " ";
			res.pop();
		}
		cout << endl;
	}
	
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> E >> U >> V;
		for(int i = 1; i <= n; i++){
			DSK[i].clear();
			vs[i] = 0;
		}
		int u, v;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			DSK[u].push_back(v);
		}
		BFS(U);
		
	}
	return 0;
}
