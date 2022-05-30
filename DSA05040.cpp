#include<bits/stdc++.h>

using namespace std;
int n;

void DP(vector<int> nums){
	vector<int> left(n, 0);
	vector<int> right(n, 0);
	left[0] = 1;
	right[n-1] = 1;
	for(int i = 1; i < n; i++){
		left[i] = 1;
		right[n - i - 1] = 1;
		if(nums[i] > nums[i-1]) left[i] = left[i-1] + 1;
		if(nums[n-i-1] > nums[n-i]) right[n-i-1] = 1 + right[n-i];
	}
	int res = 1;
	for(int i = 0; i < n; i++){
		res = max(res, left[i] + right[i] - 1);
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
		DP(nums);	
	}
	return 0;
}
