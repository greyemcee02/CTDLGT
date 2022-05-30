#include<bits/stdc++.h>

using namespace std;



bool check(vector<int> &nums, int n){
	int l = n / 2 - 1, r = n / 2;
	if(n%2 != 0){
		r = n / 2 + 1;
		if(nums[n/2] > nums[l] && nums[n/2] > nums[r]) return false;
		if(nums[n/2] < nums[l] && nums[n/2] < nums[r]) return false;
	}
	while(l >= 0 && r <= n-1){
		if(nums[l] > nums[l+1] && nums[r] < nums[r-1]){
			swap(nums[l], nums[r]);			
		}
		else if(nums[l] <= nums[l+1] && nums[r] >= nums[r-1]){
			
		}
		else if(nums[l] <= nums[l+1] && nums[r] < nums[r-1]){
			if(nums[l] >= nums[r-1] && nums[r] <= nums[l+1]) swap(nums[l], nums[r]);
			else return false;
		}
		else if(nums[l] > nums[l+1] && nums[r] >= nums[r-1]){
			if(nums[l] >= nums[r-1] && nums[r] <= nums[l+1]) swap(nums[l], nums[r]);
			else return false;
		}
		else return false;
		l--;
		r++;
	}
	return true;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		cout << (check(nums, n)?"Yes":"No") << endl;
	}
	return 0;
}
