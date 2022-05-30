#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k, tmp;
		cin >> n >> k;
		vector<int> check(1000001);
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			check[tmp]++;
		}
		if(check[k] == 0) cout << -1 << endl;
		else cout << check[k] << endl;
	}
	return 0;
}
