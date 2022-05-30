#include<bits/stdc++.h>

using namespace std;


int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> check(1000010, 0);
		int res , tmp;
		cin >> res;
		check[res]++;	
		for(int i = 1; i < n; i++) {
			cin >> tmp;
			check[tmp]++;
			if(check[tmp] > check[res])
				res = tmp;
		}
		if(check[res] > n/2) cout << res << endl;
		else cout << "NO" << endl;
	} 
	return 0;
}
