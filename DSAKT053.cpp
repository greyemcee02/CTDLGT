#include<bits/stdc++.h>

using namespace std;

string num1, num2;

void solve(){
	int n = num1.length(), m = num2.length();
	vector<vector<int>> DP(n+1, vector<int>(m+1, 0));
	for(int i = 1; i <= n; i++ ){
		for(int j = 1; j <= m; j++){
			if(num1[i-1] == num2[j-1]){
				DP[i][j] = max(DP[i-1][j-1] + 1, DP[i][j]);
			}
			else{
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
			}
		}
	}
	cout << DP[n][m] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> num1 >> num2;
		solve();
	}
	return 0;
}
