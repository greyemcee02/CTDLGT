#include<bits/stdc++.h>

using namespace std;

void out(vector<int> nums, int k){
	for(int i = 1; i <= k; i++)
		cout << nums[i];
	cout << " ";
}

void Try(vector<int> &nums, vector<int> &check, int i, int n) {
	for(int j = 1; j <= n; j++){
		if(!check[j]) {
			check[j] = 1;
			nums[i] = j;
			if(i == n) out(nums, n);
			else Try(nums, check, i + 1, n);
			check[j] = 0;
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n + 1);
		vector<int> check(n + 1, 0);
		Try(nums, check, 1, n);	
		cout << endl;
	}
	return 0;
}

