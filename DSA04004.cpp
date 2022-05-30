#include<bits/stdc++.h>

using namespace std;
int n;
long long k;
vector<long long> check(51, 1);
int solve(int n, long long k){
	if(k == check[n]) return n;
	if(k > check[n]) return solve(n-1, k-check[n]);
	if(k < check[n]) return solve(n-1, k);
}

int main() {
	for(int i = 2; i <= 50; i++)
		check[i] = check[i-1]*2;
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		cout <<  solve(n, k) << endl;
	}	
	return 0;
}
