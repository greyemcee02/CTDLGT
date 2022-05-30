#include<bits/stdc++.h>

using namespace std;
string str1, str2;

void QHD(){
	int n = str1.length(), m = str2.length();
	vector<vector<int>> DP(m + 1,vector<int>(n + 1, 0));
	for(int i = 1; i <= m; i++){
		DP[i][0] = i;
	}
	for(int i = 1; i <= n; i++){
		DP[0][i] = i;
	}
	//DP[0][0] = 1;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(str2[i-1] == str1[j-1]){
				DP[i][j] = DP[i-1][j-1];
			}
			else{
				DP[i][j] = 1 +  min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1]));
				// thay the, chen, xoa
			}
		}
	}
	cout << DP[m][n] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> str1 >> str2;
		QHD();
	}
	return 0;
}
