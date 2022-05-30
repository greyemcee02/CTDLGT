#include<bits/stdc++.h>
using namespace std;
int n, m;

int DP(vector<vector<int>> &grid){
	for(int i = 1; i < n; i++){
		grid[i][0] += grid[i-1][0];
	}
	for(int i = 1; i < m; i++){
		grid[0][i] += grid[0][i-1];
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++)
			grid[i][j] = grid[i][j] + min(grid[i-1][j-1], min(grid[i-1][j], grid[i][j-1]));
	}
	return grid[n-1][m-1];
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++ ){
				cin >> grid[i][j];
			}
		}
		cout << DP(grid) << endl;
	}
	return 0;
}
