#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> A, vector<int> C, int n, int w){
	vector<vector<int>> F(w+1, vector<int>(n+1, 0));
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= n; j++){			
			if(i >= A[j]){
				F[i][j] = max(F[i][j - 1], F[i-A[j]][j - 1] + C[j]);
			}
			else{
				F[i][j] = F[i][j - 1];
			}
		}
	}
	cout << F[w][n] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, w;
		cin >> n >> w;
		vector<int> A(n+1), C(n+1);
		for(int i = 1; i <= n; i++)
			cin >> A[i];
		for(int i = 1; i <= n; i++)
			cin >> C[i];
		solve(A, C, n, w);
	}
	return 0;
}
