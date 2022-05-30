#include<bits/stdc++.h>

using namespace std;

void qSort(int left, int right, vector<int> &vt) {
	int l = left, r = right - 1;
	int pivot = vt[( left + right )/2];
	while(l <= r){
		while(vt[l] < pivot) l++;
		while(pivot < vt[r]) r--;
		if(l <= r){
			swap(vt[l], vt[r]);
			l++;
			r--;
		}
	}
	if(l < right) qSort(l, right, vt);
	if(left < r) qSort(left, r + 1, vt);
}

void solve(vector<int> nums){
	int sz = nums.size();
	qSort(0, sz, nums);
	vector<int> tmp;
	int p1 = 0, p2 = nums.size() - 1;
	while(p1 < p2){
		tmp.push_back(nums[p2--]);
		tmp.push_back(nums[p1++]);
	}
	if(sz % 2 != 0)
		tmp.push_back(nums[p2]);
	for(auto it : tmp)
		cout << it << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		solve(nums);
	}
	return 0;
}
