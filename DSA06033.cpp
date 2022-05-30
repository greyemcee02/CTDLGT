#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> nums, int size) {
	vector<int> minLeft(size);
	minLeft[0] = nums[0];
	for(int i = 1; i < size; i++) 
		minLeft[i] = min(minLeft[i-1], nums[i]);
	int res = INT_MIN;
	int i = size - 1, j = size - 1;
	while(i >= 0 && j>= 0) {
		if(nums[j] > minLeft[i]){
			res = max(res, j - i);
			i--;
		}
		else j--;
	}
	return res;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int size;
		cin >> size;
		vector<int> nums(size);
		for(int i = 0; i < size; i++) 
			cin  >> nums[i];
		cout << solve(nums, size) << endl;
	}
	return 0;
}
