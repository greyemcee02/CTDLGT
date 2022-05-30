#include<bits/stdc++.h>

using namespace std;
int V, E;
vector<pair<int, int>> edg;
vector<int> parent(101);
vector<int> cnt(101);
priority_queue<pair<int,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;
int res;

void makeSet(){
	for(int i = 1; i <= V; i++){
		parent[i] = i;
		cnt[i] = 1;
	}
}

int find(int u){
	if(parent[u] == u) return u;
	return find(parent[u]);	
}

bool Union(int a, int b){
	int u = find(a);
	int v = find(b);
	if(u != v){
		if(cnt[u] >= cnt[v]){
			parent[v] = u;
			cnt[u] += cnt[v];
		}
		else{
			parent[u] = v;
			cnt[v] += cnt[u];
		} 
		return true;
	}
	return false;
}

void input(){
	cin >> V >> E;
	edg.clear();
	res = 0;
	makeSet();
	while(!Q.empty()) Q.pop();
	int u, v, w;
	for(int i = 1; i <= E; i++){
		cin >> u >> v >> w;
		Q.push({w, {u, v}});
	}
//	while(!Q.empty()){
//		cout << Q.top().first << " " << Q.top().second.first << " " << Q.top().second.second << endl;
//		Q.pop();
//	}
}

void Kruskal(){
	while(edg.size() < V-1 && !Q.empty()){
		int u = Q.top().second.first;
		int v = Q.top().second.second;
		int w = Q.top().first;
		Q.pop();
		if(Union(u, v)){
			res += w;
			edg.push_back({u, v});
		}
	}
	if(edg.size() == V - 1)
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		input();
		Kruskal();
	}
	return 0;
}
