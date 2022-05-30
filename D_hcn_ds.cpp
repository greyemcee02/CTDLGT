#include<bits/stdc++.h>

using namespace std;
int n, m;

long long solve(vector<int> &nums){
	vector<int>	left(n), right(n);
	stack<int> stk;
	stk.push(0);
	left[0]= -1;
	for(int i = 1; i < n; i++){
		if(stk.empty()){
			left[i] = -1;
		}
		else{
			while(!stk.empty() && nums[stk.top()] >= nums[i]){
				stk.pop();
			}
			if(stk.empty()) left[i] = -1;
			else left[i] = stk.top();
		}
		stk.push(i);
	}
	
	stack<int> stk2;
	stk2.push(n-1);
	right[n-1]= n;
	for(int i = n-2; i >= 0; i--){
		if(stk2.empty()){
			right[i] = n;
		}
		else{
			while(!stk2.empty() && nums[stk2.top()] >= nums[i]){
				stk2.pop();
			}
			if(stk2.empty()) right[i] = n;
			else right[i] = stk2.top();
		}
		stk2.push(i);
	}
	long long res = 0;
	for(int i = 0; i < n; i++){
		res = max(res, (long long)(right[i] - left[i] - 1) * nums[i]);
	}
	return res;
}

int main() {
	cin >> m >> n;
	vector<int> nums1(n), nums2(n);
	for(int i = 0; i < n; i++){
		cin >> nums1[i];
		nums2[i] = m - nums1[i];
	}
//	cout << solve(nums1);
	cout << max(solve(nums1), solve(nums2)) << endl;
	return 0;
}
