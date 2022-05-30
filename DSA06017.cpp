#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, m, tmp;
		cin >> n >> m;
		multiset<int> nums;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			nums.insert(tmp);
		}
		for(int i = 0; i < m; i++){
			cin >> tmp;
			nums.insert(tmp);
		}
		for(auto it : nums)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}
