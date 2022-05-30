#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
int n, k;

long long P(int n, int k){
	if(k > n) return 0;
	long long res = 1;
	for(int i = n; i >= n-k+1; i--){
		res = res * i;
		res%=mod;
	}
	return res;
}
int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		cout << P(n, k) << endl;
	}
	return 0;
}

