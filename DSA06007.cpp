#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> nums) {
	vector<int> nums1 = nums;
	sort(nums1.begin(), nums1.end());
	int p1 = 0, p2 = nums.size() - 1;
	while(nums[p1] == nums1[p1]) p1++;
	while(nums[p2] == nums1[p2]) p2--;
	cout << p1 + 1 << " " << p2 + 1 << endl;
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
		solve(nums);
	}	
	return 0;
}

