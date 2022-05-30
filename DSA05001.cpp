#include<bits/stdc++.h>

using namespace std;

void solve(string str1, string str2){
	int n = str1.length(), m = str2.length();
	int res = 0;
	vector<vector<int>> F(n + 1, vector<int>(m + 1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			F[i][j] = F[i-1][j-1];
			if(str1[i-1] == str2[j-1]){
				F[i][j] = max(F[i][j], F[i-1][j-1] + 1);
			}
			else{
				F[i][j] = max(F[i][j], max(F[i-1][j], F[i][j-1]));
			}
			res = max(res, F[i][j]);
		}
	}	
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		string str1, str2;
		cin >> str1 >> str2;
		solve(str1, str2);
	}
	return 0;
}
