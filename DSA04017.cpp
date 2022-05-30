#include<bits/stdc++.h>

using namespace std;

void nhap(vector<int> &nums){
	for(auto &it : nums)
		cin >> it;
}

int solve(vector<int> nums1, vector<int> nums2, int n){
	int i;
	for(i = 0; i < n - 1; i++){
		if(nums1[i] != nums2[i]) return i+1;
	}
	return n;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<int> nums1(n);
		vector<int> nums2(n - 1);
		nhap(nums1);
		nhap(nums2);
		cout << solve(nums1, nums2, n) << endl;
	}
	return 0;
}
