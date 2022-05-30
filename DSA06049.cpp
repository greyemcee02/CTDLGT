#include<bits/stdc++.h>

using namespace std;

long long solve(vector<int> nums, int k){
	long long res = 0;
	for(int i = nums.size() - 1; i > 0; i--) {
		auto p1 = upper_bound(nums.begin(), nums.end(), nums[i] - k);
		int s = p1 - nums.begin();
		if(s < i) res+= i - s;
	}
	return res;
}


int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}		
		sort(nums.begin(), nums.end());
		cout << solve(nums, k) << endl;
	}
	return 0;
}

