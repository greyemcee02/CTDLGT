#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k, tmp;
		cin >> n >> k;
		int check = -1;
		for(int i = 0; i < n ; i++){
			cin >> tmp;
			if(tmp == k) check = 1;
		}
		cout << check << endl;
	}
	return 0;
}
