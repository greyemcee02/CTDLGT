#include<bits/stdc++.h>

using namespace std;


int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, m, tmp;
		cin >> n >> m;
		int mn = INT_MAX, mx = INT_MIN;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			mx = max(mx, tmp);
		}
		for(int i = 0; i < m; i++){
			cin >> tmp;
			mn = min(mn, tmp);
		}
		cout << (long long) mn * mx << endl;
	}
	return 0;
}
