#include<bits/stdc++.h>

using namespace std;
int n, m;

void solve(){
    if(n == 0 || m == 0) {
        cout << 1 << endl;
        return;
    }
	long long F[n + 2][m+2] = {};
	for(int i = 0; i <= n; i++){
	    F[i][m] = 1;
	}
	for(int i = 0; i <= m; i++){
	    F[n][i] = 1;
	}
	for(int i = n - 1; i >= 0; i--){
	    for(int j = m - 1; j >= 0; j--){
	        F[i][j] = F[i + 1][j] + F[i][j + 1];
	    }
	}
	cout << F[0][0] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n >> m;
		solve();
	}
	
	return 0;
}
