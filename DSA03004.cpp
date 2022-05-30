#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;


int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		long long a = 0, b = 0;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++){
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		int i = 0, j = 1;
		while(i < nums.size()){
			a = a * 10 + nums[i];
			i += 2;
		}
		while(j < nums.size()){
			b = b * 10 + nums[j];
			j += 2;
		}
		cout << a + b << endl;
	}
	return 0;
}
