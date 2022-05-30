#include<bits/stdc++.h>

using namespace std;
int n, m;

int solve(vector<vector<int>> &grid){
	queue<pair<int, int>> Q;
	Q.push({0, 0});
	vector<vector<int>> check(n, vector<int> (m, INT_MAX));
	check[0][0] = 0;
	while(check[n-1][m-1] == INT_MAX){
		if(Q.empty()) return -1;
		pair<int, int> pr = Q.front();
		Q.pop();
		int  x = pr.first, y = pr.second;
		if(x + 1 < n && y < m && check[x+1][y] == INT_MAX){
			check[x+1][y] = check[x][y] + 1;
			Q.push({x+1, y});
		}
		if(x < n && y + 1 < m && check[x][y + 1] == INT_MAX){
			check[x][y + 1] = check[x][y] + 1;
			Q.push({x, y + 1});
		}
		if(x + 1 < n && y + 1 < m){
			int k = abs(grid[x][y] - grid[x+1][y+1]);
			for(int i = 1; i < = k; i++){
				if(x + i < n && y + i < m ){
					if(check[x+i][y+i] == INT_MAX)
						Q.push({x+i, y+i});
					check[x+i][y+i] = min(check[x+i][y+i], chec[x][y] + 1);
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << check[i][j] << " ";
		cout << endl;
	}
	return check[n-1][m-1];
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> m;	
		vector<vector<int>> grid(n, vector<int>(m));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		cout << solve(grid) << endl;	
	}
	return 0;
}
