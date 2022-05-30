#include<bits/stdc++.h>

using namespace std;
int n, k;

void solve(vector<int> nums){
	int p = k - 2;
	while(p >= 0 && nums[p] == nums[p + 1] - 1) p--;
	if(p == -1){
		if(nums[0] == 1){
			for(int i = 1; i <= k; i++)
				cout << n - k + i << " ";
		}
		else{
			nums[0]--;
			cout << nums[0] << " ";
			for(int i = 1; i < k; i++)
				cout << n - k + i + 1 << " ";
		}
	}
	else{
		nums[p + 1]--;
		for(int i = 0; i <= p + 1; i++)
			cout << nums[i] << " ";
		for(int i = p + 2; i < k; i++)
			cout << n - k + i + 1 << " ";
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		vector<int> nums(k);
		for(int i = 0; i < k; i++)
			cin >> nums[i];
		solve(nums);
	}
}
