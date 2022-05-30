#include<bits/stdc++.h>

using namespace std;
int n, k;
int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n >> k;
		int sum = 0;
		vector<int> num(n, 0);
		for(int i = 0; i < n; i++){
			cin >> num[i];
			sum += num[i];
		}
		if(sum % k != 0){
			cout << 0 << endl;
		}
		else{
			bool ok = true;
			for(int i = 0; i < n; i++){
				if(num[i] > k){
					ok = false;
					break;
				}
			}
			if(ok) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}
