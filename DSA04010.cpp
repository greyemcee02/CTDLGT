#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> nums, int n){
	int res = nums[0];
	vector<int> num1 = nums;
	for(int i = 1; i < n; i++){
		if(num1[i] + num1[i-1] >=0){
			num1[i] = max(num1[i], num1[i] + num1[i-1]);
		}
		res = max(res, num1[i]);
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<int> nums(n);
		for(auto &it : nums)
			cin >> it;
		solve(nums, n);
	}
	return 0;
}
