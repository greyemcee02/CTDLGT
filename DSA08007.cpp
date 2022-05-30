#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		long long n, cnt = 0;
		cin >> n;
		queue<long long> Q;
		Q.push(1);
		while(1){
			long long a = Q.front();
			Q.pop();
			if(a > n) break;
			cnt++;
			Q.push(a*10);
			Q.push(a*10+1);
		}
		cout << cnt << endl;
	}
	return 0;
}

