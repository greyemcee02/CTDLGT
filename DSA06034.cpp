#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		map<int, int> mp;
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
			mp[nums[i]]++;
		}
		long long cnt = 0;
		for(int i = 0; i < n; i++){
			if(nums[i] == k - nums[i]) cnt += ((long long)mp[nums[i]] *(mp[nums[i]] - 1)/2);
			else
			cnt += (long long)mp[nums[i]]*mp[k - nums[i]];
			mp[nums[i]] = 0;
			mp[k-nums[i]] = 0;
		}
		cout << cnt << endl;
	}
	
	return 0;
}
