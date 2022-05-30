#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<pair<int, int>> abi = {{0, 1}, {1,1}, {1, 0}, {1, -1}, {0,-1}, {-1, -1}, {-1, 0}, {-1, 1}};
void BFS(vector<vector<int>> &grid, int h, int c){
	queue<pair<int, int>> Q;
	Q.push({h, c});
	grid[h][c] = 0;
	while(!Q.empty()){
		pair<int, int> pr = Q.front();
		Q.pop();
		for(auto it : abi){
			if(pr.first + it.first <= n-1 && pr.first + it.first >= 0 && 
			pr.second + it.second <= m-1 && pr.second + it.second >= 0 ){
				if(grid[pr.first + it.first][pr.second + it.second]){
					grid[pr.first + it.first][pr.second + it.second] = 0;
					Q.push({pr.first + it.first, pr.second + it.second});
				}				
			}
		}		
	}
}

int solve(vector<vector<int>> &grid){
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j]){
				res++;
				BFS(grid, i, j);
			}
		}
	}
	return res;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(auto &it : grid[i])
				cin >> it;
		}	
		cout << solve(grid) << endl;	
	}	
	return 0;
}
