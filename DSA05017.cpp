#include<bits/stdc++.h>

using namespace std;

void QHD(vector<int> nums, int n){
	vector<int> left(n), right(n,0);
	for(int i = 0; i < n; i++){
		left[i] = nums[i];
		for(int j = 0; j < i; j++){
			if(nums[i] > nums[j]){
				left[i] = max(left[i], left[j] + nums[i]);
			}
		}
	}
	for(int i = n - 1; i >= 0; i--){
		right[i] = nums[i];
		for(int j = n - 1; j > i; j--){
			if(nums[i] > nums[j]){
				right[i] = max(right[i], right[j] + nums[i]);
			}
		}
	}
	int res = left[0] + right[0] - nums[0];
	for(int i = 1; i < n; i++){
		res = max(res, left[i] + right[i] - nums[i]);
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<int> nums(n, 0);
		for(auto &it : nums)
			cin >> it;
		QHD(nums, n);
	}
	return 0;
}
