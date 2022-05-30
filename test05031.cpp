#include<bits/stdc++.h>

using namespace std;
vector<int> F(10001, 0);
void solve(){
	for(int i = 1; i <= 10000; i++){
		if(i*i <= 10000) F[i*i] = 1;
		if(!F[i]){
			F[i] = F[1] + F[i - 1];
			for(int j = 2; j <= i/2; j++){
				F[i] = min(F[i], F[j] + F[i-j]);
			}
		}
	}
}

int main() {
	solve();
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		cout << F[n] << endl;
	}
	
	return 0;
}
