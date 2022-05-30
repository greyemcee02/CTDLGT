#include<bits/stdc++.h>

using namespace std;
int n, k;
int mod = 1e9 + 7;
void DP(){
	vector<long long> F(n + 1, 0);
	F[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= min(k, i); j++){
			F[i] += F[i-j];
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
		DP();		
	}
	return 0;
}
