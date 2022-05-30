#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> nums, int size) {
	int mn = nums[1] - nums[0];
	for(int i = 2; i < size; i++) {
		int tmp = nums[i] - nums[i-1];
		if(tmp < mn) mn = tmp; 
	}
	return mn;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int size;
		cin >> size;
		vector<int> nums(size);
		for(int i = 0; i < size; i++) 
			cin >> nums[i];
		sort(nums.begin(), nums.end());
		cout << solve(nums, size) << endl;
	}
	return 0;
}

