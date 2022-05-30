#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> nums, int n, int sum){
	vector<int> check(10001, 0);
	check[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = sum; j >= nums[i]; j--){
			if(check[j - nums[i]]){
				check[j] = 1;
				if(j == sum) return 1; 
			}
		}
	}
	return check[sum];
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, sum = 0;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i];
			sum += nums[i];
		}
		if(sum%2!=0){
			cout << "NO" << endl;
		}
		else{
			cout << (solve(nums, n, sum/2) ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
