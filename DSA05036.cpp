#include<bits/stdc++.h>

using namespace std;
int n;

void DP(vector<pair<double, double>> nums){
	vector<int> F(n, 1);
	int res = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(nums[i].first > nums[j].first && nums[i].second < nums[j].second){
				F[i] = max(F[i], F[j] + 1);
			}
		}
		res = max(res, F[i]);
	}
	cout << res << endl;
}
int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<pair<double, double>> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i].first >> nums[i].second;
		DP(nums);	
	}
	return 0;
}
