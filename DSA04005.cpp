#include<bits/stdc++.h>

using namespace std;
int n;
long long k;
vector<long long> check(94, 1);
char solve(int n, long long k){
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	if(k > check[n-2]) return solve(n-1, k - check[n-2]); 
	else return solve(n-2, k);
}

int main() {
	for(int i = 3; i <= 93; i++)
		check[i] = check[i-1] + check[i-2];
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		cout <<  solve(n, k) << endl;
	}	
	return 0;
}
