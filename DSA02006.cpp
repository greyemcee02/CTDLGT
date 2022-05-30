#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> res;
int n, k;
void Try(vector<int> &nums, vector<int> &s, int i, int sum) {
	for(int j = 1; j >= 0; j--) {
		sum += j*nums[i];
		if(j == 1)
		s.push_back(nums[i]);
		if(sum >= k || i == n - 1){
			if(sum == k) res.push_back(s);
		}
		else Try(nums, s, i + 1, sum);
		sum -= j*nums[i];
		if(j == 1)
		s.pop_back();
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		res.clear();
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		sort(nums.begin(), nums.end());
		vector<int> s;
		Try(nums, s, 0, 0);
		if(res.empty()) cout << -1;
		else{
			for(auto it : res){
				cout << "[";
				for(int i = 0; i < it.size() - 1; i++)
					cout << it[i] << " ";
				cout << it[it.size() - 1] << "] ";
			}
		}
		cout << endl;
	}
	return 0;
}
