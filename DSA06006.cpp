#include<bits/stdc++.h>

using namespace std;


int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, tmp;
		cin >> n;
		vector<int> nums(3);
		for(int i = 0; i < n; i++){
			cin >> tmp;
			nums[tmp]++;
		}
		for(int i = 0; i <= 2; i++){
			while(nums[i]--){
				cout << i << " ";
			}
		}
		cout << endl;
	}	
	return 0;
}

