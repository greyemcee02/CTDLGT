#include<bits/stdc++.h>

using namespace std;

vector<int> MG = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, res = 0;
		cin >> n;
		for(int i = 0; i < MG.size(); i++){
			if(n >= MG[i]){
				int a = n/MG[i];
				res += a;
				n -= MG[i] * a;
			}
		}
		cout << res << endl;
	}	
	
	return 0;
}
