#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &nums, int n, int k) {
	int i = k - 1;
	while(i >= 0 && nums[i] == n - k + i + 1){
		i--;
	} 
	if(i == -1) 
		for(int i = 0; i < k; i++) 
			cout << i + 1 << " ";
	else{
		nums[i]++;
		for(int j = i + 1; j < k; j++)
			nums[j] = nums[j - 1] + 1;
		for(auto it : nums)
			cout << it << " ";
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(k);
		for(int i = 0; i < k; i++)
			cin >> nums[i];
		solve(nums, n, k);		
	}
	return 0;
}

