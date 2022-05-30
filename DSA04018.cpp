#include<bits/stdc++.h>

using namespace std;

void nhap(vector<int> &nums){
	for(auto &it : nums)
		cin >> it;
}

int countZero(vector<int> nums, int n){
	int l = 0, r = n - 1;
	if(nums[0] == 1) return 0;
	if(nums[n-1] ==0) return n;
	while(l < r){
		int mid = (l + r + 1)/2;
		if(nums[mid] == 0){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	return l + 1;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<int> nums(n);
		nhap(nums);
		cout << countZero(nums, n) << endl;
	}
	return 0;
}
