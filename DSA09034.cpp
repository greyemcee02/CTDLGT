#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<int, int>> graph = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
vector<vector<char>> vec;
void input(){
	cin >> n >> m;
	vec.resize(n, vector<char>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> vec[i][j];
	}
}

void BFS(int u, int v){
	queue<pair<int, int>> Q;
	Q.push({u, v});
	vec[u][v] = '.';
	while(!Q.empty()){
		pair<int, int> pr = Q.front();
		Q.pop();
		for(auto it : graph){
			if(pr.first + it.first >= 0 && pr.first + it.first < n && pr.second + it.second >= 0 && pr.second + it.second < m ){
				if(vec[pr.first + it.first][pr.second + it.second] == 'W'){
					vec[pr.first + it.first][pr.second + it.second] = '.';
					Q.push({pr.first + it.first, pr.second + it.second});
				}
			}
		}
	}
}

void solve(){
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(vec[i][j] =='W'){
				res++;
				BFS(i, j);
			}
		}
	}
	cout << res << endl;
}


int main() {
	input();
	solve();
	return 0;
}
//10 12
//W........WW.
//.WWW.....WWW
//....WW...WW.
//.........WW.
//.........W..
//..W......W..
//.W.W.....WW.
//W.W.W.....W.
//.W.W......W.
//..W.......W.
