#include<bits/stdc++.h>

using namespace std;
int n;
void solve(vector<int> nums){
	vector<int> DP(n);
	DP[0] = nums[0];
	int res = nums[0];
	for(int i = 1; i < n; i++){
		DP[i] = nums[i];
		for(int j = 0; j < i; j++){
			if(nums[i] > nums[j]){
				DP[i] = max(DP[i], DP[j] + nums[i]); 
			}
		}
		res = max(res, DP[i]);
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<int> nums(n);
		for(auto &it : nums)
			cin >> it;
		solve(nums);
	}
	return 0;
}
