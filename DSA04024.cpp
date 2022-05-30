#include<bits/stdc++.h>

using namespace std;
int n, k;
int mod = 1e9 + 7;
vector<vector<long long>> operator*(vector<vector<long long>> res, vector<vector<long long>> nums){
	vector<vector<long long>> tmp(n, vector<long long> (n));
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res.size(); j++){
			for(int k = 0; k < res.size(); k++){
				tmp[i][j] = tmp[i][j] + (res[i][k] * nums[k][j])%mod;
				tmp[i][j]%=mod;
			}
		}
	}
	return tmp;
}

vector<vector<long long>> pow(vector<vector<long long>> nums, long long k){
	if(k == 1) return nums;
	vector<vector<long long>> res = pow(nums, k/2);
	if(k%2==0) return res * res;
	else return res * res * nums;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		vector<vector<long long>> nums(n, vector<long long>(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> nums[i][j];
		}
		nums = pow(nums, k);
		long long res = 0;
		for(int i = 0; i < n; i++){
			res = res + nums[i][n-1];
			res %= mod;
		}
		cout << res << endl;
	}
	return 0;
}
