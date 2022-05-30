#include<bits/stdc++.h>

using namespace std;

void merge(int left, int mid, int right, vector<int> &nums) {
	vector<int> v1, v2;
	for(int i = left; i <= mid; i++)
		v1.push_back(nums[i]);
	for(int i = mid + 1; i <= right; i++)
		v2.push_back(nums[i]);
	int p1 = 0, p2 = 0, p = left;
	while(p1 < v1.size() && p2 < v2.size()){
		if(v1[p1] < v2[p2]){
			nums[p++] = v1[p1++];
		}
		else{
			nums[p++] = v2[p2++];
		}
	}
	while(p1 < v1.size()){
		nums[p++] = v1[p1++];
	}
	while(p2 < v2.size()){
		nums[p++] = v2[p2++];
	}
}

void mSort(int left, int right, vector<int> &nums) {
	if(left < right) {
		int mid = (left + right)/2;
		mSort(left, mid, nums);
		mSort(mid + 1, right, nums);
		merge(left, mid, right, nums);
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		mSort(0, n - 1, nums);
		for(auto it : nums)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}
