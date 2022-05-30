#include<bits/stdc++.h>

using namespace std;
int n;
void solve(vector<int> nums){
	stack<int> stk;
	vector<int> res(n);
	for(int i = n-1; i >= 0; i--){
		while(!stk.empty() && stk.top() <= nums[i]){
			stk.pop();
		}
		if(stk.empty()){
			res[i] = -1;
		}
		else res[i] = stk.top();
		stk.push(nums[i]);
	}
	for(auto it : res)
		cout << it << " ";
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		solve(nums);
	}
	return 0;
}
