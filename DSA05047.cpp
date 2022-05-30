#include<bits/stdc++.h>

using namespace std;
int n;


void DP(vector<vector<int>> &nums){
	int res = INT_MIN;
	vector<vector<int>> F1(4, vector<int>(n, 0));
	vector<vector<int>> F2(4, vector<int>(n, 0));
	F1[0][0] = 0;
	for(int i = 0; i < n; i++){
		
	}
	for(int i = 2; i <= 4; i++){
		for(int j = 2; j <= n; j++){
			F1[i][j] = max(F1[i][j], max(F1[i][j-1], F2[i][j-1]));
			F1[i][j] = max(F1[i][j], max(F1[i-1][j-1], F2[i-1][j-1]));
			F1[i][j] = max(F1[i][j], max(F1[i-1][j], F2[i-1][j]));
			F1[i][j] = max(F1[i][j], max(F1[i-1][j+1], F2[i][j+1]));
			
			F2[i][j] = max(F2[i][j], max(F1[i][j-1], F1[i-1][j]) + nums[i][j]);
			F2[i][j] = max(F2[i][j], max(F2[i-1][j-1], F2[i-1][j+1]) + nums[i][j]);
			res = max(res, max(F2[i][j], F1[i][j]));
		}
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<vector<int>> nums(4, vector<int>(n));
		for(int  i = 0; i < 4; i++){
			for(int j = 0; j < n; j++)
				cin >> nums[i][j];
		}
		DP(nums);
	}
	return 0;
}
