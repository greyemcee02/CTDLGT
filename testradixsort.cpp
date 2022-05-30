#include<bits/stdc++.h>

using namespace std;
int n;

void radixsort(vector<string> &nums) {
	int n = nums.size();
	int maxsize = 0;
	for(auto it : nums) {
		if(maxsize < it.length()) maxsize = it.length();
	}
	while(maxsize > 0) {
		vector<int> count(10, 0);
		for(int i = 0; i < n; i++) {
			count[(char)nums[i][maxsize - 1] - '0']++;
		}
		for(auto it : count)
			cout << it << " ";
		cout << endl;
		for(int i = 1; i <= 9; i++)
			count[i] += count[i-1];
		vector<string> tmp(n);
		for(int i = n - 1; i >= 0; i--) {
			tmp[count[nums[i][maxsize - 1] - '0'] - 1] = nums[i];
			count[nums[i][maxsize - 1] - '0']--;
		}
		nums = tmp;
		maxsize--;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		vector<string> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		radixsort(nums);
//		for(auto it : nums)
			//cout << it << endl;
	}
	return 0;
}
