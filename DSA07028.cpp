#include<bits/stdc++.h>

using namespace std;
int n;

void solve(vector<int> &nums){
	stack<int> stk;
	vector<int> res;
	res.push_back(1);
	stk.push(0);
	for(int i = 1; i < nums.size(); i++){
		if(stk.empty()){
			stk.push(i);
			res.push_back(1);
		}
		else{
			int k;
			while(!stk.empty()){
				k = stk.top();
				if(nums[i] < nums[k]){
					res.push_back(i - k);
					break;
				}
				stk.pop();
			}
			if(stk.empty()){
				res.push_back(i + 1);
			}
			stk.push(i);
		}
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
		for(auto &it : nums)
			cin >> it;
		solve(nums);
	}
	return 0;
}
