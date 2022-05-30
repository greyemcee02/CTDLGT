#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		int ok = 1;
		for(int i = 0; i < n - 1; i++){
			if(nums[i] >= nums[i+1]){
				ok = 0;
				break;
			}
		}		
		cout << ok << endl;
	}
	return 0;
}
