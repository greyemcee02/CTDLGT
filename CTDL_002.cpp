#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> res;
int n, k;
void Try(vector<int> nums, vector<int> s, int i, int sum) {
	for(int j = 0; j <= 1; j++) {
		s[i] = j;
		sum += j * nums[i];
		if(i == n - 1) {
			if(sum == k) res.push_back(s);
		}
		else Try(nums, s, i + 1, sum);
		sum -= j * nums[i];
	}
}

int main() {
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int> s(n);
	Try(nums, s, 0, 0);
	for(int i = 0; i < res.size(); i++) {
		vector<int> tmp = res[i];
		for(int j = 0; j < tmp.size(); j++) {
			if(tmp[j]) cout << tmp[j]*nums[j] << " ";
		}
		cout << endl;
	}
	cout << res.size();
	return 0;
}

