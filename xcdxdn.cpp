#include<bits/stdc++.h>
using namespace std;
string str;

void DP(){
	int n = str.length();
	vector<vector<int>> F(n + 1, vector<int>(n + 1, 0));
	for(int i = 1; i <= n; i++){
		F[i][i] = 1;
	}
	int res = 1;
	for(int k = 1; k < n; k++){
		for(int i = 0; i < n - k; i++){
			int j = i + k;
			if(str[i] == str[j]){
				if(k == 1) F[i][j] = 1;
				else F[i][j] = F[i+1][j-1];
			}
			else F[i][j] = 0;
			if(F[i][j]) res = max(res, j -i + 1);
		}
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> str;
		DP();
	}
	return 0;
}
