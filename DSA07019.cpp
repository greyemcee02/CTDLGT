#include<bits/stdc++.h>

using namespace std;
int n;

void solve(vector<int> nums){
	int n = nums.size();
	vector<int> left(n), right(n);
	stack<int> l, r;
	for(int i = 0; i < n; i++){
		while(!l.empty()){
			int k = l.top();
			if(nums[k] < nums[i]){
				left[i] = k;
				l.push(i);
				break;
			}
			else{
				l.pop();
			}
		}
		if(l.empty()) left[i] = -1;
		l.push(i);
	}
	for(int i = n-1; i >= 0; i--){
		while(!r.empty()){
			int k = r.top();
			if(nums[k] < nums[i]){
				right[i] = k;
				r.push(i);
				break;
			}
			else{
				r.pop();
			}
		}
		if(r.empty()) right[i] = n;
		r.push(i);
	}
	long long res = 0;
	for(int i = 0; i < n; i++){
		res = max(res, (long long)(right[i]-left[i]-1)*nums[i]);
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >>  n;
		vector<int> nums(n);
		for(auto &it : nums)
			cin >> it;
		solve(nums);
	}
	return 0;
}
