#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> nums, int size) {
	vector<int> nums1(size), nums2(size);
	nums1[0] = nums[0];
	nums2[size - 1] = nums[size - 1];
	for(int i = 1; i < size; i++){
		nums1[i] = nums1[i - 1] + nums[i];
	}
	for(int i = size - 2; i >= 0; i--){
		nums2[i] = nums2[i + 1] + nums[i];
	}
	for(int i = 0; i < size; i++) {
		if(nums1[i] == nums2[i]) return i+1;
	}
	return -1;
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
		cout << solve(nums, size) << endl;
	}
	return 0;
}

