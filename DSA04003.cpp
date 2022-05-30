#include<bits/stdc++.h>

using namespace std;
int mod = 123456789;
long long solve(long long n){
	if(n == 0) return 1;
	long long s = solve(n/2);
	if(n % 2 == 0)
		return ((s%mod)*s)%mod;
	else
		return ((((s%mod)*s)%mod)*2)%mod;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		long long n;
		cin >> n;
		cout << solve(n - 1) << endl;
	}	
	return 0;
}
