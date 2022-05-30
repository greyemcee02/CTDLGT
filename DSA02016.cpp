#include<bits/stdc++.h>

using namespace std;
int n, cnt;
void Try(int i, vector<int> check, vector<int> chinh, vector<int> phu) {
	for(int j = 0; j < n; j++) {
		if(!check[j] && !chinh[i - j + n - 1] && !phu[i + j]) {
			check[j] = 1;
			chinh[i - j + n - 1] = 1;
			phu[i + j] = 1;
			if( i == n - 1) {
				cnt++;
			}
			else Try(i + 1, check, chinh, phu);
			check[j] = 0;
			chinh[i - j + n - 1] = 0;
			phu[i + j] = 0;
		}
	}
}


int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		vector<int> check(n, 0), chinh(2*n - 1, 0), phu(2*n - 1, 0);
		cnt = 0;
		Try(0, check, chinh, phu);
		cout << cnt << endl;
	}
	return 0;
}

