#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums, int n, int k) {
	for(int p1 = 0; p1 < n - 2; p1++) {
		int p2 = p1 + 1, p3 = n - 1;
		while(p2 < p3) {
			long long sum = (long long)nums[p1] + nums[p2] + nums[p3];
			if(sum == k) return 1;
			else if(sum < k) p2++;
			else p3--;
		}
	}
	return 0;
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
		sort(nums.begin(), nums.end());
		cout << (solve(nums, n, k)?"YES":"NO") << endl;
	} 
	return 0;
}
