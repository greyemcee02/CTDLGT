#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> nums, vector<int> nums1){
	int res = 0;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] != nums1[i]){
			for(int j = i + 1; j < nums.size(); j++){
				if(nums[j] == nums1[i]){
					swap(nums[j], nums[i]);
					res++;
					break;
				}
			}
			
		}
	}
	return res;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		vector<int> nums1 = nums;
		sort(nums1.begin(), nums1.end());
		cout << solve(nums, nums1) << endl;
	}
	return 0;
}
