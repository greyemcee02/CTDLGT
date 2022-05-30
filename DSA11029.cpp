#include<bits/stdc++.h>

using namespace std;
vector<int> DSK[1001];
int n;
vector<vector<int>> res;
void DFS(int u, vector<int> vec){
	vec.push_back(u);
	if(DSK[u].size() == 0){
		res.push_back(vec);
		vec.pop_back();
		return;
	}
	for(auto v : DSK[u]){
		DFS(v, vec);
	}
	vec.pop_back();
}

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		DSK[i].clear();
	}
	int u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		DSK[u].push_back(v);
	}
	res.clear();
}
 
bool cmp(vector<int> v1, vector<int> v2){
	int p1 = v1.size() - 1, p2 = v2.size() - 1;
	while(p1 >= 0 && p2 >= 0){
		if(v1[p1] < v2[p2]) return true;
		else if(v1[p1] > v2[p2]) return false;
		p1--; p2--;
	}
	if(p1 < p2) return true;
	return false;
} 

void solve(){
	vector<int> vec;
	DFS(1, vec);
	sort(res.begin(), res.end(), cmp);
	for(auto it : res){
		for(auto i : it)
			cout << i << " ";
		cout << endl;
	}
}
 

int main() {
	int test;
	cin >> test;
	while(test--){
		input();
		solve();
	}
	return 0;
}
