#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
vector<vector<long long>> CKN(1001, vector<long long>(1001, 0));
int n, k;
void solve(){
	CKN[0][0] = 1;
	for(int i = 1; i <= 1000; i++){
		for(int j = 0; j <= i; j++){
			if(i == 0 || j == 0 || j == i) CKN[i][j] = 1;
			else{
				CKN[i][j] = CKN[i-1][j-1] + CKN[i-1][j];
				CKN[i][j] %= mod;
			}
		}
	}
}

int main() {
	solve();
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		cout << CKN[n][k] << endl;
	}
	return 0;
}
