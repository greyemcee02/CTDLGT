#include<bits/stdc++.h>

using namespace std;

int n, k, s;
int cnt;

void Try(int i, int sum, vector<int> save) {
	for(int j = save[i-1] + 1; j <= n - k + i; j++) {
		save[i] = j;
		sum += j;
		if(sum > s){
			sum -= j;
			break;
		}
		if(i == k) {
			if(sum == s) cnt++;
		}
		else Try(i + 1, sum, save);
		sum -= j;
	}
}

int main() {
	while(1) {
		cin >> n >> k >> s;
		if(n == 0 && k == 0 && s == 0) break;
		cnt = 0;
		vector<int> save(k + 1, 0);
		Try(1, 0, save);
		cout << cnt << endl;
	}
	return 0;
}
