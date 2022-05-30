#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> check(100001, 0);
void solve(){
	check[2] = 1;
	check[3] = 1;
	for(int i = 4; i <= 100001; i++){
		check[i] = check[i-1] + 1;
		if(i % 2 == 0 && i % 3 == 0){
			check[i] = min(check[i], min(1 + check[i/2], 1 + check[i/3]));
		}
		else if(i % 3 == 0 && i % 2 != 0){
			check[i] = min(check[i], 1 + check[i/3]);
		}
		else if(i % 3 != 0 && i % 2 == 0)
			check[i] = min(check[i], 1 + check[i/2]);
	}
}

int main() {
	solve();
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		cout << check[n] << endl;
	}
	return 0;
}



