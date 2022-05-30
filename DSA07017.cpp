#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &nums, int n){
	vector<int> res(n), right(n);
	stack<int> stk;
	right[n-1] = -1;
	stk.push(n-1);
	for(int i = n - 2; i >= 0; i--){
		if(stk.empty()){
			right[i] = -1;
			stk.push(i);
		}
		else{
			while(!stk.empty()){
				int k = stk.top();
				if(nums[k] < nums[i]){
					right[i] = nums[k];
					break;
				}
				stk.pop();
			}
			if(stk.empty())
				right[i] = -1;
			stk.push(i); 
		}
	}
	
	stack<int> stk2;
	stk2.push(n-1);
	res[n-1] = -1;
	for(int i = n - 2; i >= 0; i--){
		if(stk2.empty()){
			res[i] = -1;
			stk2.push(i);
		}
		else{
			while(!stk2.empty()){
				int k = stk2.top();
				if(nums[k] > nums[i]){
					res[i] = right[k];
					break;
				}
				stk2.pop();
			}
			if(stk2.empty())
				res[i] = -1;
			stk2.push(i); 
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
		int n;
		cin >> n;
		vector<int> nums(n);
		for(auto &it : nums)
			cin >> it;
		solve(nums, n);
	}
	return 0;
}
