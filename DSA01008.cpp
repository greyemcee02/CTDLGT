#include<bits/stdc++.h>

using namespace std;

void out(vector<int> nums, int n) {
	for(int i = 1; i <= n; i++)
		cout << nums[i];
	cout << endl;
}

void Try(vector<int> &nums, int i, int n, int k, int cnt) {
	for(int j = 0; j <= 1; j++){
		if(j) cnt++;
		nums[i] = j;
		if(i == n){
			if(cnt == k)
				out(nums, n);
		}
		else Try(nums, i + 1, n, k, cnt);
		if(j) cnt--;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n + 1, 0);
		Try(nums, 1, n, k, 0);
	}
	return 0;
}

