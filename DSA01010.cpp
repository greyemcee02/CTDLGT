#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> ps, vector<int> check, int n, int k){
	int i = k - 1, cnt = 0;
	while(i >= 0 && ps[i] == n - k + i + 1) i--;
	if(i == -1) return k;
	ps[i]++;
	for(int j = i + 1; j < k; j++){
		ps[j] = ps[j - 1] + 1;
	}
	for(int i = 0; i < k; i++){
		if(!check[ps[i]]) cnt++;
	}
	return cnt;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, k;
		cin >> n >> k;
		vector<int> ps(k);
		vector<int> check(41, 0);
		for(int i = 0; i < k; i++){
			cin >> ps[i];
			check[ps[i]] = 1;
		}
		cout << solve(ps, check, n, k) << endl;
	}
	
	return 0;
}
