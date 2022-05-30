#include<bits/stdc++.h>

using namespace std;
int n, V;
vector<int> C(1001), A(1001);

void solve(){
	vector<vector<int>> DP(V + 1, vector<int>(n + 1, 0));
	for(int i = 1; i <= V; i++){
		for(int j = 1; j <= n; j++){
			if(A[j] <= i){
				DP[i][j] = max(DP[i-A[j]][j-1]+C[j], DP[i][j-1]);
			}
			else{
				DP[i][j] = DP[i][j-1];
			}
		}
	}
	cout << DP[V][n] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> V;
		C.clear();
		A.clear();
		for(int i = 1; i <= n; i++)
			cin >> A[i];
		for(int i = 1; i <= n; i++)
			cin >> C[i];
		solve();
	}
	return 0;
}
