#include<bits/stdc++.h>

using namespace std;
int n;

bool cmp(pair<int, int> p1, pair<int, int> p2){
	if(p1.second < p2.second) return true;
	if(p1.second == p2.second){
		if(p1.first < p2.first) return true;
	}
	return false;
}

void DP(vector<pair<int, int>> nums){
	vector<int> F(n);
	int res = 0;
	F[0] = 1;
	sort(nums.begin(), nums.end(), cmp);
//	for(auto it : nums)
//		cout << it.first << " " << it.second << endl;
	for(int i = 1; i < n; i++){
		F[i] = 1;
		for(int j = 0; j < i; j++){
			if(nums[i].first > nums[j].second){
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
		vector<pair<int, int>> nums(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i].first >> nums[i].second;
		}
		DP(nums);
	}
	
	return 0;
}
