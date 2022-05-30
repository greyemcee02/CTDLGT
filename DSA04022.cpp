#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<int> save(28, 0);

int solve(int n, int k){
	if(n == 0 || k == save[n-1] + 1) return n;
	if(k > save[n-1] + 1) return solve(n - 1, k - save[n-1] - 1);
	else return solve(n-1, k);
}

int main() {
	save[0] = 1;
	for(int i = 1; i <= 25; i++)
		save[i] = 2*save[i-1] + 1;
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		cout << (char)('A' + solve(n - 1, k)) << endl;
	}
	
	return 0;
}

