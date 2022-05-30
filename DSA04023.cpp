#include<bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		long long res = 0;
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		sort(nums.begin(), nums.end());
		for(int i = n-1; i >= 0; i--){
			auto p = upper_bound(nums.begin(), nums.end(), nums[i] - k);
			int tmp = p - nums.begin();
			if(tmp != n)
			res += (i - tmp);
		}
		cout << res << endl;
	}
	return 0;
}


