#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
vector<vector<long long>> F(101, vector<long long>(10, 0));

void solve(){
	for(int i = 9; i >= 1; i--)
		F[1][i] = 1;
	F[1][0] = 10;
	for(int i = 2; i <= 100; i++){
		F[i][0] += F[i-1][0];
		F[i][9] = 1;
		F[i][0]++;
		F[i][0] %= mod;
		for(int j = 8; j >= 1; j--){
			F[i][j] = F[i-1][j] + F[i][j+1];
			F[i][j]%=mod;
			F[i][0] += F[i][j];
			F[i][0] %= mod;
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
		cout << F[n][0] << endl;	
	}

	return 0;
}
