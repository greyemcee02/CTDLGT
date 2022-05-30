#include<bits/stdc++.h>

using namespace std;

void out(vector<int> nums) {
	bool ok = true;
	for(int i = 1; i < nums.size() - 1; i++) {
		if(nums[i] == nums[i-1] && nums[i]) ok = false;
	}
	if(ok){
		for(auto it : nums){
			if(it) cout << 'H';
			else cout << 'A';
		}
		cout << endl;
	}
}

void Try(vector<int> nums, int i, int n){
	for(int j = 0; j <= 1; j++){
		nums[i] = j;
		if(i == n) out(nums);
		else Try(nums, i + 1, n);
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n, 1);
		nums[n - 1] = 0;
		if(n == 2) cout << "HA" << endl;
		else
		Try(nums, 1, n - 2);
	}
	return 0;
}

