#include<bits/stdc++.h>

using namespace std;

bool cmp(int a, int b){
	return a > b;
}

void solve(vector<int> nums, int k){
	sort(nums.begin(), nums.end(), cmp);
	for(int i = 0; i < k; i++)
		cout << nums[i] << " ";
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		solve(nums, k);
	}
	return 0;
}
