#include<bits/stdc++.h>

using namespace std;
int n;

void result(vector<int> &left, vector<int> &right, vector<int> &nums){
	int res = 0;
	for(int i = 0; i < n; i++){
		if(right[i] - left[i] - 1 >= nums[i])
			res = max(res, nums[i]);
	}
	cout << res << endl;
}

void solve(vector<int> &nums){
	vector<int> left(n), right(n);
	stack<int> stk1;
	left[0] = -1;
	stk1.push(0);
	for(int i = 1; i < n; i++){
		if(stk1.empty()){
			left[i] = -1;
		}
		else{
			while(!stk1.empty() && nums[stk1.top()] >= nums[i]){
				stk1.pop();
			}
			if(stk1.empty()){
				left[i] = -1;
			}
			else
				left[i] = stk1.top();
		}
		stk1.push(i);
	}
	
	stack<int> stk2;
	right[n-1] = n;
	stk2.push(n-1);
	for(int i = n-2; i >= 0; i--){
		if(stk2.empty()){
			right[i] = n;
		}
		else{
			while(!stk2.empty() && nums[stk2.top()] >= nums[i]){
				stk2.pop();
			}
			if(stk2.empty()){
				right[i] = n;
			}
			else
				right[i] = stk2.top();
		}
		stk2.push(i);
	}
	result(left, right, nums);
}



int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<int> nums(n);
		for(auto &it : nums)
			cin	>> it;
		solve(nums);
	}
	return 0;
}

//4
//7
//5 2 4 3 3 1 4
//3
//2 2 2
//2
//6 6
//6
//5 5 5 5 3 1
