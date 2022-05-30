#include<bits/stdc++.h>

using namespace std;
int n;

void solve(vector<int> nums, vector<int> xh){
	stack<int> stk;
	vector<int> res(n);
	res[n-1] = -1;
	stk.push(n-1);
	for(int i = n-2; i >= 0; i--){
		if(stk.empty())
			res[i] = -1;
		else{
			while(!stk.empty() && xh[i] >= xh[stk.top()]){
				stk.pop();
			}
			if(stk.empty())
				res[i] = -1;
			else
				res[i] = nums[stk.top()];
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
		vector<int> nums(n), count(1000001, 0), xh(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i];
			count[nums[i]]++;
		}
		for(int i = 0; i < n; i++){
			xh[i] = count[nums[i]];
		}
		solve(nums, xh);
	}
	return 0;
}
