#include<bits/stdc++.h>

using namespace std;
int mod = 1e9+7;

vector<vector<long long>> operator*(vector<vector<long long>> v1, vector<vector<long long>> v2){
	vector<vector<long long>> res(2, vector<long long> (2, 0));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				res[i][j] += v1[i][k]*v2[k][j];
				res[i][j] %= mod;
			}
		}
	}
	return res;
}

vector<vector<long long>> pow(vector<vector<long long>> Fibo, int n){
	if(n == 1) return Fibo;
	vector<vector<long long>> res = pow(Fibo, n/2);
	if(n%2==0) return res*res;
	else return res*res*Fibo;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector <vector<long long>> Fibo(2, vector<long long>(2, 1));
		Fibo[0][0] = 0;
		Fibo = pow(Fibo, n);
		cout << Fibo[0][1] << endl;
	}
	return 0;
}
