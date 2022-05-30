#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;


int main() {
	int test;
	cin >> test;
	while(test--){
		int n, k;
		int a = 0, b = 0;
		cin >> n >> k;
		//k = min(k, n - k);
		vector<int> nums(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		for(int i = 0; i < n; i++){
			if(i < k) a+= nums[i];
			else b+=nums[i];
		}
		cout << b - a << endl;
	}
	return 0;
}
