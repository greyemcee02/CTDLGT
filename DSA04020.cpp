#include<bits/stdc++.h>

using namespace std;

void nhap(vector<int> &nums){
	for(auto &it : nums)
		cin >> it;
}

int search(vector<int> nums, int n, int k){
	int l = 0, r = n - 1;
	if(nums[0] > k) return -1;
	if(nums[n-1] < k) return -1;
	while(l <= r){
		int mid = (l + r)/2;
		if(nums[mid] == k){
			return mid;
		}
		else if(nums[mid] < k){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return -1;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		nhap(nums);
		int res = search(nums, n, k);
		if(res!=-1) cout << res+1 << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
