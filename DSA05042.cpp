#include<bits/stdc++.h>

using namespace std;
int n;
long long k;

string solve(vector<long long> nums){
	long long res = 0;
	vector<long long> DP(n);
	DP[0] = nums[0];
	int x =n + 1;
	for(int i = 1; i < n; i++){
		if(nums[i] == k) return "YES";
		DP[i] = nums[i] + DP[i-1];
		if(DP[i] == k) return "YES";
		if(DP[i] > k && x > i) x = i; 
	}
	for(int i = x; i < n; i++){
		int l = 0, r = i - 1;
		while(l <= r){
			int mid = (l + r)/2;
			if(DP[i] - DP[mid] == k) return "YES";
			else if(DP[i] - DP[mid] > k) l = mid+1;
			else r = mid - 1;
		}
	}
	return "NO";
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		vector<long long> nums(n);
		for(auto &it : nums)
			cin >> it;
		cout << solve(nums) << endl;
	}
	return 0;
}
