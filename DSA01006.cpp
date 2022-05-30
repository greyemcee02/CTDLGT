#include<bits/stdc++.h>

using namespace std;

void out(vector<int> nums, int k){
	for(int i = 1; i <= k; i++)
		cout << nums[i];
	cout << " ";
}

void Try(vector<int> &nums, vector<int> &check, stack<vector<int>> &stk, int i, int n) {
	for(int j = 1; j <= n; j++){
		if(!check[j]) {
			check[j] = 1;
			nums[i] = j;
			if(i == n) stk.push(nums);
			else Try(nums, check, stk, i + 1, n);
			check[j] = 0;
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n + 1);
		vector<int> check(n + 1, 0);
		stack<vector<int>> stk;
		Try(nums, check, stk, 1, n);
		while(!stk.empty()) {
			vector<int> tmp = stk.top();
			stk.pop();
			out(tmp, n);
		}
		cout << endl;
	}
	return 0;
}

