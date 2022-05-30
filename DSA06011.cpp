#include<bits/stdc++.h>

using namespace std;


int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		int res = INT_MAX;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(abs(nums[i] + nums[j]) < abs(res))
					res = nums[i] + nums[j];
			}
		}
		cout << res << endl;
	}	
	return 0;
}
