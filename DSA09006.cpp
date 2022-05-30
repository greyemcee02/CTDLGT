#include<bits/stdc++.h>

using namespace std;
int V, E, v1, v2;
vector<vector<int>> DSK(1001);

void DFS(int u){
	vector<int> vs(V + 1, 0);
	//vector<int> duong(V+1);
	vector<int> stk;
	stk.push_back(u);
	vs[u] = 1;
	while(!stk.empty()){
		int k = stk[stk.size()-1];
		if(k == v2) break;
		stk.pop_back();
		for(auto vi : DSK[k]){
			if(!vs[vi]){
				vs[vi] = 1;
				stk.push_back(k);
				stk.push_back(vi);
				break;
			}
		}
	}
	for(auto it : stk)
		cout << it << " ";
	cout << endl;
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
		DFS(v1);
	}
	return 0;
}
