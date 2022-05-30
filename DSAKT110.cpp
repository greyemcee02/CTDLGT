#include<bits/stdc++.h>

using namespace std;
int n;

void solve(vector<int> house){
	vector<int> DP(n, 0);
	DP[0] = house[0];
	DP[1] = max(house[0], house[1]);
	for(int i = 2; i < n; i++){
		DP[i] = max(DP[i-1], house[i] + DP[i-2]);
	}
	cout << DP[n-1] << endl;
}

int main(){
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<int> house(n);
		for(auto &it : house)
			cin >> it;
		solve(house);
	}
	return 0;
}
