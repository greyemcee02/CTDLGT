#include<bits/stdc++.h>

using namespace std;
vector<int> nums;
int n;


void preOrder(int l, int r){
	if( l <= r){
		int m = (r + l)/2;
		cout << nums[m] << " ";
		if(l < m) preOrder(l, m-1);
		if(m < r) preOrder(m + 1, r);
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		nums.resize(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		sort(nums.begin(), nums.end());
		preOrder(0, n - 1);
		cout << endl;
	}
	return 0;
}

