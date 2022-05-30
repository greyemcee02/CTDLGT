#include<bits/stdc++.h>

using namespace std;
int n, s;

bool solve(vector<int> nums){
	vector<int> check(40001, 0);
	check[0] = 1;
	for(auto it : nums){
		for(int j = s; j >= it; j--){
			if(check[j-it]) check[j] = 1;
		}
	}
	return check[s];
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> s;
		vector<int> nums(n);
		for(auto &it : nums)
			cin >> it;
		if(solve(nums)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
