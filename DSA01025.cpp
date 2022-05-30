#include<bits/stdc++.h>

using namespace std;

void out(vector<int> nums, int k){
	for(int i = 1; i <= k; i++) {
		cout << (char)(nums[i] + 'A');
	}
	cout << endl;
}

void Try(int i, int n, int k, vector<int> &nums) {
	for(int j = nums[i - 1] + 1; j < n - k + i; j++) {
		nums[i] = j;
		if(i == k) out(nums, k);
		else Try(i + 1, n, k, nums);
	}
}  

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(k + 1, -1);
		Try(1, n, k, nums);
	}
	return 0;
}

