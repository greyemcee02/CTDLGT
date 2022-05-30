#include<bits/stdc++.h>

using namespace std;

int n, k;

void Try(int i, int a, vector<int> nums, vector<int> save){
	for(int j = a + 1; j <= n - k + i; j++){
		save.push_back(nums[j]);
		if(i == k - 1){
			for(auto it : save)
				cout << it << " ";
			cout << endl;
		}
		else Try(i + 1, j, nums, save);
		save.pop_back();
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		sort(nums.begin(), nums.end());
		Try(0, -1, nums, {});
	}
	return 0;
}
