#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >>n;
	vector<int> vec(n + 1);
	vector<int> check(n + 1);
	vector<int> count(n + 1, 1);
	for(int i = 1; i <= n; i++){
		cin >> vec[i];
		check[vec[i]] = i;
	}
	int rs = 1;
	for(int i = 2; i <= n; i++){
		if(check[i] > check[i-1]){
			count[i] = count[i-1] + 1;
			rs = max(rs, count[i]);
		}
	}
	cout << n - rs << endl;
	return 0;
}
