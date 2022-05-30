#include<bits/stdc++.h>

using namespace std;
int n, m;

void DP(vector<vector<int>> nums){
	vector<vector<int>>  dp(n, vector<int>(m));
	dp[0][0] = nums[0][0];
	for(int i = 1; i < n; i++){
		dp[i][0] = dp[i-1][0] + nums[i][0];
	}
	for(int i = 1; i < m; i++){
		dp[0][i] = dp[0][i-1] + nums[0][i];
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			dp[i][j] = nums[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
		}
	}
	cout << dp[n-1][m-1] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> m;
		vector<vector<int>> nums(n, vector<int>(m));
		for(int i = 0 ; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> nums[i][j];
			}
		}
		DP(nums);
	}
	return 0;
}
