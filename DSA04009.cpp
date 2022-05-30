#include<bits/stdc++.h>

using namespace std;
int mod = 1e9+7;
int n;
vector<vector<long long>> operator*(vector<vector<long long>> v1, vector<vector<long long>> v2){
	vector<vector<long long>> res(n, vector<long long> (n, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int x = 0; x < n; x++){
				res[i][j] += v1[i][x]*v2[x][j];
				res[i][j] %= mod;
			}
		}
	}
	return res;
}

vector<vector<long long>> pow(vector<vector<long long>> nums, int k){
	if(k == 1) return nums;
	vector<vector<long long>> res = pow(nums, k/2);
	if(k%2==0) return res*res;
	else return res*res*nums;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int k;
		cin >> n >> k;
		vector<vector<long long>> nums;
		vector<long long> tmp(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> tmp[j];
			nums.push_back(tmp);
		}
		nums = pow(nums, k);
		for(auto it : nums){
			for(auto i : it)
				cout << i << " ";
			cout << endl;
		}
	}
	return 0;
}
