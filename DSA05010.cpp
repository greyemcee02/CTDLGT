#include<bits/stdc++.h>

using namespace std;
int n, k;
int num[1001];
void solve(){
    vector<vector<int>> F(n + 1, vector<int>(k, 0));
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j < k; j++){
    		if(num[i-1] %k==0){
    			if(j == 0 || F[i-1][j] != 0)
    				F[i][j] = F[i-1][j] + 1;
			}
			else{
				if(F[i][(num[i-1])%k] == 0){
					F[i][num[i-1]%k] = 1;
				}
				F[i][(j+num[i-1])%k] = max(F[i-1][(j+num[i-1])%k], F[i-1][j]?(F[i-1][j] + 1):0);
			}
    		
		}
//		for(int j = 0; j < k; j++)
//			cout << F[i][j] << " ";
//		cout << endl;
	}
	cout << F[n][0] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n >> k;
		for(int i = 0; i < n; i++)
			cin >> num[i];
		solve();
	}
	
	return 0;
}
