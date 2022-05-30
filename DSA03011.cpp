#include<bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int solve(priority_queue<int, vector<int>, greater<int>> Q){
	long long res = 0;
	while(Q.size() > 1){
		int a = Q.top(); a%= mod;
		Q.pop();
		int b = Q.top(); b%= mod;
		Q.pop();
		res += a + b;
		res %= mod;
		Q.push((a + b)%mod);
	}
	return (int)res;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, tmp;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> Q;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			Q.push(tmp);
		}
		cout << solve(Q) << endl;
	}
	return 0;
}
