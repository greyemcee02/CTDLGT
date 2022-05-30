#include<iostream>
#include<algorithm>
using namespace std;

int solve(int n, int s, int m){
	if(n < m) return -1;
	if(n == m){
		if(s <= 6) return s;
		else return -1;
	}
	if((n * 6) < m * 7) return -1;
	int k = m * s;
	if(k <= n) return 1;
	if(k % n == 0) return k/n;
	else return k/n + 1;
}



int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, s, m;
		cin >> n >> s >> m;
		cout << solve(n, s, m) << endl;
	}
	return 0;
}
