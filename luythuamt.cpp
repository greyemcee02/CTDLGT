

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n, k;
int mod = 1e9 + 7;
vector<vector<long long>> operator *(vector<vector<long long>> a, vector<vector<long long>> b){
	vector<vector<long long>> vec(n, vector<long long>(n) );
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int x = 0; x < n; x++){
				vec[i][j] += (a[i][x] * b[x][j])%mod;
				vec%= mod;
			}
		}
	}
	return vec;
}

vector<vector<long long>> pow(vector<vector<long long>> F, int k ){
	if(k == 1) return F;
	vector<vector<long long>> tmp = pow(F, k/2);
	if(k % 2 == 0) return tmp * tmp;
	else return tmp * tmp * F; 
}


int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		vector<vector<long long>> F(n, vector<long long>(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> F[i][j];
		}
		vector<vector<long long>> res = pow(F, k);
		int s = 0;
		for(int i = 0; i < n; i++){
			s += res[0][i];
			s %= mod;
		}
		cout << s << endl;
	}
	return 0;
}
