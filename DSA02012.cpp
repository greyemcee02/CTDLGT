#include<bits/stdc++.h>

using namespace std;

void phanTich(int n, vector<int> &count) {
	for(int i = 2; i <= n; i++) {
		int tmp = i;
		while(tmp%2 == 0){
			count[2]++;
			tmp/=2;
		}
		for(int j = 3; j <= sqrt(tmp); j+=2){
			while(tmp % j == 0) {
				count[j]++;
				tmp/=j;
			}
		}
		if(tmp > 1) count[tmp]++;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		vector<int> count1(200, 0), count2(200, 0);
		int n, m, tmp;
		cin >> n >> m;
//		for(int i = 0; i < n; i++){
//			for(int j = 0; j < m; j++)
//				cin >> tmp;
//		}
		if(n < m) swap(n, m);
		n = n + m - 2;
		m = m - 1;
		phanTich(n, count1);
		phanTich(m, count2);
		phanTich(n - m, count2);
		for(int i = 2; i < 200; i++) {
			count1[i] = count1[i] - count2[i];
		}
		long long tu = 1, mau = 1;
		for(int i = 2; i < 200; i++) {
			if(count1[i] >= 0){
				for(int j = 1; j <= count1[i]; j++){
					tu *= i;
					if(tu%mau == 0){
						tu /= mau;
						mau = 1;
					}
				}
			}
			else{
				for(int j = 1; j <= count1[i]; j++){
					mau *= i;
				}
			}
		}
		cout << tu/mau << endl;
	}
	return 0;
}
