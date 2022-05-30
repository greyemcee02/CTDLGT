#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>> DP(101, vector<long long>(10));
int mod = 1e9 + 7;

void solve(){
	for(int i = 1; i <= 9; i++){
		DP[1][i] = 1;
	}
	DP[1][0] = 10;
	for(int i = 2; i <= 100; i++){
		DP[i][9] = 1;
 		DP[i][0] = DP[i-1][0] + 1;
		DP[i][0] %= mod;
		for(int j = 8; j >= 1; j--){
			DP[i][j] = (DP[i-1][j] + DP[i][j+1])%mod;
			DP[i][0] += DP[i][j];
			DP[i][0] %= mod;
		}
	}
}

int main() {
	solve();
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		cout << DP[n][0] << endl;
	}
	return 0;
}
