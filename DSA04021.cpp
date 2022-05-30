#include<bits/stdc++.h>

using namespace std;
int n;
long long k;
vector<long long> save(93, 0);

int solve(int n, long long k){
	if(n == 1) return 0;
	if(n == 2) return 1;
	if(k > save[n-2])
		return solve(n-1, k - save[n-2]);
	else return solve(n-2, k);
}

int main() {
	save[1] = 1;
	save[2] = 1;
	for(int i = 2; i <= 92; i++)
		save[i] = save[i-1] + save[i-2];
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
	return 0;
}

