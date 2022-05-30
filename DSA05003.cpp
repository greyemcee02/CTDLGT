#include<bits/stdc++.h>

using namespace std;
int x, y, z;
string X, Y, Z;
void solve(){
	vector<vector<vector<int>>> DP(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, 0)));
	for(int i = 1; i <= x; i++){
		for(int j = 1; j <= y; j++){
			for(int k = 1; k <= z; k++){
				if(X[i - 1] == Y[j-1] && X[i-1] == Z[k-1]){
					DP[i][j][k] = DP[i-1][j-1][k-1] + 1;
				}
				else{
					DP[i][j][k] = max(DP[i-1][j-1][k-1], max(DP[i][j - 1][k], DP[i][j][k-1]));
					DP[i][j][k] = max(DP[i][j][k], DP[i-1][j][k]);	
				}
			}
		}
	}
	cout << DP[x][y][z] << endl;
}


int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> x >> y >> z;
		cin >> X >> Y >> Z;
		solve();
	}
	return 0;
}
