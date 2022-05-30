#include<bits/stdc++.h>

using namespace std;

bool ok;
int cnt;
void sinh(vector<int> &nums){
	int i = nums.size() - 2;
	while(nums[i] < nums[i + 1] && i >= 0) i--;
	if(i == -1){
		ok = true;
	}
	else{
		int a = i + 1, b = nums.size() - 1;
		while(a < b){
			swap(nums[a], nums[b]);
			a++;
			b--;
		}
		int j = i + 1;
		while(nums[i] < nums[j] && j < nums.size()) j++;
			swap(nums[i], nums[j]);
		cnt++;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		ok = false;
		cnt = 1;
		while(!ok){
			sinh(nums);
		}
		cout << cnt << endl;
	}
	return 0;
}
