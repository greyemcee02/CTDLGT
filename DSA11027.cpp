#include<bits/stdc++.h>

using namespace std;
vector<int> nums;
int n;

int countLeaf(int l, int r){
	if(l == r){
		return 1;
	} 
	if(l < r){
		int m = (l + r)/2;
		int x = 0, y = 0;
		if(l < m) x = countLeaf(l, m - 1);
		if(r > m) y = countLeaf(m + 1, r);
		return x + y;
	}
}

//15 20 23 25 28 30 33 35 38 40 45

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		nums.resize(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		sort(nums.begin(), nums.end());	
		cout << countLeaf(0, n - 1) << endl;
	}
	return 0;
}
