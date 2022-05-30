#include<bits/stdc++.h>

using namespace std;
int n;
vector<long long> F(51, 0);
void solve(){
	F[0] = 1;
	for(int i = 1; i <= 50; i++){
		for(int j = min(3, i); j >= 1; j--){
			F[i] = F[i] + F[i - j]; 
		}
	}
}

int main() {
	solve();
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		cout << F[n] << endl;
	}
	return 0;
}
