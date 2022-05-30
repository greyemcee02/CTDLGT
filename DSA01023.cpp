#include<bits/stdc++.h>

using namespace std;

bool ok;
int cnt;
void sinh(vector<int> &nums, int n, int k){
	int i = k;
	while(nums[i] == nums[i - 1] + 1 && i >= 1) i--;
	if(i == 0){
		ok = true;
	}
	else{
		nums[i]--;
		for(int j = i + 1; j <= k; j++)
			nums[j] = n - k + j;
		cnt++;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(k+1, 0);
		for(int i = 1; i <= k; i++)
			cin >> nums[i];
		ok = false;
		cnt = 1;
		while(!ok){
			sinh(nums, n, k);
		}
		cout << cnt << endl;
	}
	return 0;
}
