#include<bits/stdc++.h>

using namespace std;
int n;

void solve(vector<int> nums){
	vector<int> F(n, 1);
	int res = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(nums[i] > nums[j])
				F[i] = max(F[i], F[j] + 1);
		}
		res = max(res, F[i]);
	}
	cout << res << endl;
}

int main() {
	cin >> n;
	vector<int> nums(n);
	for(auto &it : nums)
		cin >> it;
	solve(nums);
	return 0;
}
