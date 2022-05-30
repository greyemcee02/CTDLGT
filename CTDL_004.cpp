#include<bits/stdc++.h>

using namespace std;
int n, k;
int cnt = 0;

void solve(vector<int> save, vector<int> nums) {
	if(save.size() != k) return;
	for(int i = 0; i < save.size() - 1; i++){
		if(nums[save[i]] > nums[save[i+1]]) return;
	}	
	cnt++;
}

void Try(int i, vector<int> save, vector<int> nums) {
	for(int j = 1; j >= 0; j--) {
		if( j == 1) {
			save.push_back(i);
		}
		if(i == n - 1){
			solve(save, nums);
		}
		else Try(i + 1, save, nums);
		if(j == 1)
			save.pop_back();
	}
}

int main() {
	cin >> n >> k;
	cnt = 0;
	vector<int> save, nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	Try(0, save, nums);
	cout << cnt << endl;
	return 0;
}
