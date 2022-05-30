#include<bits/stdc++.h>

using namespace std;
int n;

void solve(vector<int> &nums){
	stack<int> stk;
	vector<int> res(n);
	res[0] = 1;
	stk.push(0);
	for(int i = 1; i < n; i++){
		if(stk.empty()){
			stk.push(i);
			res[i] = 1;
		}
		else{
			while(!stk.empty() && nums[stk.top()] <= nums[i]){
				stk.pop();
			}
			if(stk.empty()){
				res[i] = i + 1;
			}
			else{
				res[i] = i - stk.top();
			}
		}
		stk.push(i);
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
