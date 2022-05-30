#include<bits/stdc++.h>

using namespace std;

int C, n;

void solve(vector<int> W){
	vector<int> check(25001, 0);
	check[0] = 1;
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = C; j >= W[i]; j--){
			if(check[j - W[i]]){
				check[j] = 1;
				res = max(res, j);
			} 
		}
	}
	cout << res << endl;
}

int main() {
	cin >> C >> n;
	vector<int> W(n);
	for(int i = 0; i < n; i++)
		cin >> W[i];
	solve(W);
	return 0;
}
