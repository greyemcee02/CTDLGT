#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> nums, int k){
	int sz = nums.size();
	deque<int> dq;
	for(int i = 0; i < sz; i++) {
		while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
		dq.push_back(i);
		if(dq.front() + k <= i) dq.pop_front();
		
		if(i >= k - 1) cout << nums[dq.front()] << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		solve(nums, k);
	}
	return 0;
}
