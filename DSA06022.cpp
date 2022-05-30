#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> nums){
	int sz = nums.size();
	vector<int> res;
	if(sz == 1 || (sz == 2 && nums[0] == nums[1])){
		res.push_back(-1);
		return res;
	}
	int m1 = nums[0], m2 = nums[0];
	for(int i = 1; i < sz; i++){
		if(nums[i] < m1){
			m2 = m1;
			m1 = nums[i];
		}
		else if(nums[i] < m2){
			m2 = nums[i];
		}
	}
	if(m1 == m2){
		res.push_back(-1);
	}
	else{
		res.push_back(m1);
		res.push_back(m2);
	}
	return res;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n ; i++){
			cin >> nums[i];
		}
		vector<int> res = solve(nums);
		for(auto it : res)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}
