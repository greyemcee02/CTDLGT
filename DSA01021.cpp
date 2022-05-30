#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums, int n, int k) {
	vector<int> check(100, 0);
	for(auto it : nums)
		check[it] = 1;
	int i = k - 1;
	while(i >= 0 && nums[i] == n - k + i + 1) i--;
	int cnt = 0;
	if(i == -1) return k;
	else{
		nums[i]++;
		if(check[nums[i]] == 0) cnt++;
		for(int j = i + 1; j < k; j++){
			nums[j] = nums[j - 1] + 1;
			if(check[nums[j]] == 0) cnt++;
		}
		return cnt;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(k);
		for(int i = 0; i < k; i++)
			cin >> nums[i];
		cout << solve(nums, n, k) << endl;
	}
	return 0;
}

