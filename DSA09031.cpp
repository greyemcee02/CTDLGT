#include<bits/stdc++.h>

using namespace std;
int n, m, k;
vector<vector<int>> A;
vector<int> tp;
int cnt;
vector<pair<int, int>> nx = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


void input(){
	cin >> n >> k >> m;
	A.resize(2*n + 1, vector<int>(2*n + 1, 1));
	for(int i = 0; i < 2*n+1; i++){
		A[i][0] = 0;
		A[0][i] = 0;
		A[i][2*n] = 0;
		A[2*n][i] = 0;
	}	
	int u, v, x, y;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> x >> y;
		u = 2*u-1;
		v = 2*v-1;
		x = 2*x-1;
		y = 2*y-1;
		u = (u+x)/2;
		v = (v+y)/2;
		A[u][v] = 0;
	}
	for(int i = 1; i <= k; i++){
		cin >> u >> v;
		A[2*u-1][2*v-1] = 2;	
	}				
}

bool check(int i, int j){
	if(i <= 0 || i >= 2*n|| j <= 0 || j >= 2*n) return false;
	if(A[i][j] == 0) return false;
	return true;
}

void BFS(pair<int, int> td){
	queue<pair<int, int>> Q;
	Q.push(td);
	if(A[td.first][td.second]==2)
		cnt++;
	A[td.first][td.second] = 0;
	while(!Q.empty()){
		pair<int, int> pr = Q.front();
		Q.pop();
		for(auto it : nx){
			if(A[it.first + pr.first][it.second+pr.second] == 1 && check(2*it.first + pr.first, 2*it.second+pr.second)){
				if(A[2*it.first + pr.first][2*it.second+pr.second] == 2)
					cnt++;
				//cout << cnt << endl;
				A[2*it.first + pr.first][2*it.second+pr.second] = 0;
				Q.push({2*it.first + pr.first, 2*it.second+pr.second});
			}
		}
	}


}

void solve(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(A[2*i-1][2*j-1]){
				cnt = 0;
				BFS({2*i-1, 2*j-1});
				if(cnt > 0)
					tp.push_back(cnt);
			}
		}
	}
	long long res = 0;
	for(int i = 0; i < tp.size()-1; i++){
		for(int j = i + 1; j < tp.size(); j++)
			res += (long long)tp[i]*tp[j];
	}
	cout << res << endl;
}

int main() {
	input();
	solve();
	return 0;
}
//4 4 4
//
//2 2 2 3
//
//3 3 3 2
//
//3 3 2 3
//
//3 4 3 3
//
//3 3
//
//2 2
//
//2 3
//
//1 2
