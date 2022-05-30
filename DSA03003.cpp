#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;


int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		long long res = 0;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		for(int i = 0; i < n; i++){
			
			res += i * nums[i];
			res = res % mod;
		}
		cout << res << endl;
	}
	return 0;
}
