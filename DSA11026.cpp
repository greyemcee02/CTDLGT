#include<bits/stdc++.h>

using namespace std;
vector<int> nums;
int n;

void postOrder(int l, int r){
	if(l <= r){
		int m = (l + r )/2;
		if(l < m) postOrder(l, m - 1);
		if(r > m) postOrder(m + 1, r);
		cout << nums[m] << " ";
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
		postOrder(0, n - 1);
		cout << endl;
	}
	return 0;
}
