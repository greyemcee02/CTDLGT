#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &nums, int n) {
	int i = n - 2;
	while(i >= 0 && nums[i] > nums[i + 1] ) i--;
	if(i == -1) {
		for(int j = 0; j < n; j++)
			cout << j + 1 << " ";
	}
	else{
		int j = n - 1;
		while(nums[j] < nums[i]) j--;
		swap(nums[i], nums[j]);
		int p1 = i + 1, p2 = n - 1;
		while(p1 < p2){
			swap(nums[p1], nums[p2]);
			p1++;
			p2--;
		}
		for(int j = 0; j < n; j++) {
			cout << nums[j] << " ";
		}
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		solve(nums, n);		
	}
	return 0;
}

