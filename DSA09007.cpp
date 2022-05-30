#include<bits/stdc++.h>

using namespace std;
int V, E, v1, v2;
vector<vector<int>> DSK(1001);

void BFS(int u){
	vector<int> vs(V + 1, 0);
	vector<int> bf(V+1);
	queue<int> Q;
	Q.push(u);
	vs[u] = 1;
	bf[u] = 0;
	bool ok =  false;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		if(v == v2){
			ok = true;
			break;
		}
		for(auto vi:DSK[v]){
			if(!vs[vi]){
				vs[vi] = 1;
				Q.push(vi);
				bf[vi] = v;
			}
		}
	}
	if(ok){
		stack<int> res;
		int v = v2;
		while(v!= 0){
			res.push(v);
			v = bf[v];
		}
		while(!res.empty()){
			cout << res.top() << " ";
			res.pop();
		}
			
		cout << endl;
	}
	else{
		cout << -1 << endl;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> V >> E >> v1 >> v2;
		for(int i = 0; i <= V; i++)
			DSK[i].clear();
		int t1, t2;
		for(int i = 0; i < E; i++){
			cin >> t1 >> t2;
			DSK[t1].push_back(t2);
			DSK[t2].push_back(t1);
		}	
		BFS(v1);
	}
	return 0;
}
