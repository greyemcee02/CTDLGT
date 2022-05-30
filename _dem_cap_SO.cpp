#include<bits/stdc++.h>

using namespace std;
int n;

void solve(vector<int> &nums){
	stack<int> stk;
	stk.push(0);
	int res = 0;
	for(int i = 1; i < n; i++){
		while(stk.size() > 1 && nums[stk.top()] <= nums[i])
			stk.pop();
		res += i - stk.top();
		if(nums[i] >= nums[stk.top()])
			stk.pop();
		stk.push(i);
	}
	cout << res << endl;
}

int main() {
	cin >> n;
	
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	solve(nums);
	return 0;
}
