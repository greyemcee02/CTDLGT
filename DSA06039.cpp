#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			cin >> nums[i];
			mp[nums[i]]++;
		}
		int res = -1;
		for(int i = 0; i < n; i++) {
			if(mp[nums[i]] > 1){
				res = nums[i];
				break;
			}
		}
		if(res == -1) cout << "NO" << endl;
		else cout << res << endl;
	}
	
	return 0;
}
