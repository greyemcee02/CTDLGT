#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> nums;

void solve(){
	int res = 0;
	for(int i = 0; i < nums.size(); i++)
		if(nums[i] > 0) res += 2*nums[i];
	cout << res << endl;
}

int main() {
	cin >> n;
	nums.resize(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	solve();
	return 0;
}
