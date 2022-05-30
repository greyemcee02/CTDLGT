#include<bits/stdc++.h>

using namespace std;
string num;

void DP(){
	int n = num.length();
	long long res = 0;
	vector<vector<long long>> F(n, vector<long long>(n, 0));
	for(int i = 0; i < n; i++){
		F[0][i] = num[i] - '0';
		res += F[0][i];
	}	
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= i ; j++){
			F[j][i] = F[j-1][i-1]*10 + F[0][i];
			res += F[j][i];
		}
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> num;	
		DP();	
	}
	return 0;
}
