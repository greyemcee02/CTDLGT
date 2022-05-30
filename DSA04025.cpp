#include<bits/stdc++.h>

using namespace std;
long long n;
int mod = 1e9 + 7;
vector<vector<long long>> operator*(vector<vector<long long>> res, vector<vector<long long>> nums){
	vector<vector<long long>> tmp(2, vector<long long> (2));
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
		cin >> n;
		vector<vector<long long>> nums(2, vector<long long>(2, 1));
		nums[0][0] = 0;
		if(n <= 1){
			if(n == 0) cout << 0 << endl;
			else cout << 1 << endl;
		}
		else{
			nums = pow(nums, n);
			cout << nums[0][1] << endl;
		}
	}
	return 0;
}
