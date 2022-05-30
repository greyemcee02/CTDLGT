#include<bits/stdc++.h>

using namespace std;


int main() {
	int test;
	cin >> test;
	while(test--){
		int n, x;
		cin >> n >> x;
		int k = -1, res = -1, tmp;
		for(int i = 1; i <= n; i++){
			cin >> tmp;
			if(tmp <= x){
				if(tmp > res){
					res = tmp;
					k = i;
				}
			}
		}
		cout << k << endl;
	}
	return 0;
}
