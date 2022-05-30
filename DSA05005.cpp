#include<bits/stdc++.h>

using namespace std;
int n;

int solve(vector<int> nums){
	vector<int> F(n, 1);
	int res = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(nums[i] >= nums[j])
				F[i] = max(F[i], F[j] + 1);
		}
		res = max(res, F[i]);
	}
	return res;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<int> nums(n);
		for(auto &it : nums)
			cin >> it;
		int k = solve(nums);
		cout << n - k << endl;
	}
	return 0;
}
