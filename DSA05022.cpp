#include<bits/stdc++.h>

using namespace std;
int n, x, y, z;

void QHD(){
	vector<int> DP(n + 1);
	DP[1] = x;
	for(int i = 2; i <= n; i++){
		if(i%2==0){
			DP[i] = min(DP[i-1] + x, DP[i/2] + z);
		}
		else{
			DP[i] = min(DP[i-1] + x, min(DP[i/2] + z + x, DP[i/2 + 1] + z + y));
		}
	}
	cout << DP[n] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> x >> y >> z;
		QHD();
	}
	return 0;
}
