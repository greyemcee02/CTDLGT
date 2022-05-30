#include<bits/stdc++.h>

using namespace std;

long long solve(vector<int> nums, int k) {
	long long res = 0;
	for(int i = 0; i < nums.size() - 2; i++) {
		if(nums[i] >= k) continue;
		for(int j = i + 1; j < nums.size() - 1; j++){
			long long sum = nums[i] + nums[j];
			if(sum + nums[j+1] >= k) continue;
			int left = j + 1, right = nums.size() - 1;
			while(left < right) {
				int mid = (left + right + 1)/2;
				if(sum + nums[mid] >= k) right = mid - 1;
				else{
					left = mid;
				}
			}
			if(sum + nums[left] < k)
				res += left - j;
		}
		
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		sort(nums.begin(), nums.end());
		cout << solve(nums, k) << endl;
	}
	return 0;
}
