#include<bits/stdc++.h>

using namespace std;
int n, m;


void solve(vector<int> num1, vector<int> num2){
	vector<int> res(n+m - 1, 0);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			res[i+j] += num2[i] * num1[j];
		}
	}
	for(auto it :res)
		cout << it << " ";
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n >> m;
		vector<int> num1(n), num2(m);
		for(auto &it : num1)
			cin >> it;
		for(auto &it : num2)
			cin >> it;
		solve(num1, num2);
	}
	return 0;
}
