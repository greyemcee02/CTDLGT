#include<bits/stdc++.h>

using namespace std;

void out(vector<int> nums, int k){
	for(int i = 1; i <= k; i++)
		cout << nums[i];
	cout << " ";
}

void Try(vector<int> &nums, int i, int n, int k) {
	for(int j = nums[i - 1] + 1; j <= n - k + i; j++){
		nums[i] = j;
		if(i == k) {
			out(nums, k);
		}
		else Try(nums, i + 1, n, k);
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(k + 1, 0);
		Try(nums, 1, n, k);	
		cout << endl;
	}
	return 0;
}

