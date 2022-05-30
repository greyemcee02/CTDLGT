#include<bits/stdc++.h>

using namespace std;
int parent[1001];
int V, E;

void makeSet(){
	for(int i = 1; i <= V; i++){
		parent[i] = i;
	}
}

int Find(int u){
	if(parent[u] == u) return u;
	return Find(parent[u]);	
}

bool Union(int a, int b){
	int u = Find(a);
	int v = Find(b);
	if(u != v){
		parent[u] = v;
		return true;
	} 
	return false;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> V >> E;
		makeSet();
		int u, v;
		bool ok = false;
		for(int i = 1; i <= E; i++){
			cin >> u >> v;
			if(!Union(u, v)) ok = true;
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	return 0;
}

//2
//4 3
//1 2 1 3 3 4
//4 4 
//1 2 1 3 3 4 4 1
