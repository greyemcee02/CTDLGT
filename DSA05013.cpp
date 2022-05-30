#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
int n, k;
void solve(){
	vector<long long> F(n + 1, 0);
	F[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = min(k, i); j >= 1; j--){
			F[i] = F[i] + F[i - j]; 
			F[i] %= mod;
		}
	}
	cout << F[n] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		solve();
	}
	return 0;
}
