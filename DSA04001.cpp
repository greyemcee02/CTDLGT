#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
long long solve(int n, int k){
	if(k == 0) return 1;
	long long res = solve(n, k/2);
	if(k%2 == 0) return ((res % mod) * res)%mod;
	else return ((((res % mod) * res)%mod)*n)%mod;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
	return 0;
}
