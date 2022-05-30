#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solve(vector<int> nums, int n) {
	int res = nums[n-1] * nums[n-2];
	if(n == 3)
		res = max(res, max(nums[0]*nums[1], nums[n-3] * res));
	else if(n >= 4) 
		res = max(res, max(nums[0] * nums[1] * nums[n-1], max(nums[n-1]*nums[n-2]*nums[n-3], nums[0] * nums[1])));
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	cout << solve(nums, n) << endl;
	
	return 0;
}
