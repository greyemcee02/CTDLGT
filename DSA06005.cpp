#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> s1, vector<int> s2, int n, int m) {
	map<int, int> hop;
	vector<int> giao;
	for(int i = 0; i < n; i++) {
		hop[s1[i]]++;
	}
	for(int i = 0; i < m; i++){
		hop[s2[i]]++;
		if(hop[s2[i]] == 1){
			hop[s2[i]]--;
		}
		else {
			hop[s2[i]] -= 2;
			giao.push_back(s2[i]);
		}
	}
	for(auto it : hop)
		cout << it.first << " ";
	cout << endl;
	for(auto it : giao)
		cout << it << " ";
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, m;
		cin >> n >> m;
		vector<int>  s1(n), s2(m);
		for(int i = 0; i < n; i++)
			cin >> s1[i];
		for(int i = 0; i < m; i++)
			cin >> s2[i];
		solve(s1, s2, n, m);
	}	
	return 0;
}

