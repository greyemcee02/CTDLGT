#include<bits/stdc++.h>

using namespace std;
int n, m;

void solve(vector<vector<int>> vec){
	vector<vector<int>> DP(n, vector<int>(m));
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i == 0 || j == 0){
				DP[i][j] = vec[i][j];
			}
			else{
				if(vec[i][j] == 1){
					DP[i][j] = 1 + min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1]));
				}
			}
			res = max(res, DP[i][j]);
		}
	}
	cout << res  << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> m;
		vector<vector<int>> vec(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> vec[i][j];
		}
		solve(vec);
	}
	return 0;
}
