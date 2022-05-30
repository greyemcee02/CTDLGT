#include<bits/stdc++.h>

using namespace std;

int search(int l, int r, int k, vector<int> nums){
	if(l <= r){
		int m = (l + r)/2;
		if(nums[m] == k) return m;
		int res = search(l, m - 1, k, nums); 
		if(res != -1) return res;
		else return search(m + 1, r, k, nums);
	}
	return -1;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0; i < n ; i++){
			cin >> nums[i];
		}
		cout << search(0, n - 1, k, nums) + 1<< endl;
	}
	return 0;
}
