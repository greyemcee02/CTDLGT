#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int solution(vector<int> nums, int k){
	vector<int> DP(k + 1, 0);
	DP[0] = 1;
	for(int i = 1; i <= k; i++){
		for(auto it : nums){
			if(it <= i){
				DP[i] += DP[i-it];
				DP[i] = DP[i] % mod;
			}
		}
	}
	return DP[k];
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for(auto &it : nums){
			cin >> it;
		}
		cout << solution(nums, k) << endl;
		
	}
	return 0;
}
