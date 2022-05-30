#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<vector<int>> res;
bool ok ;
void Try(int i, int pos, int s, vector<int> save, vector<int> nums) {
	for(int j = pos; j < n; j++){
		s += nums[j];
		save.push_back(nums[j]);
		if(s == k ){
			if(s == k){
				ok = true;
				res.push_back(save);
			} 
		}
		else if(s < k) Try(i + 1, j, s, save, nums);
		s -= nums[j];
		save.pop_back();
	}
}

void out() {
	for(auto it : res){
		cout << "[";
		for(int i = 0; i < it.size() - 1; i++)
			cout << it[i] << " ";
		cout << it[it.size() - 1] << "]";
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		vector<int> nums(n), save;
		res.clear();
		ok = false;
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		sort(nums.begin(), nums.end());
		Try(0, 0, 0, save, nums);
		if(ok)
			out();
		else cout << -1 << endl;
	}
	return 0;
}
