#include<bits/stdc++.h>

using namespace std;
int n, k;
set<string> res;

void solve(vector<int> save, vector<int> nums) {
	string str;
	if(save.size() <= 1) return;
	for(int i = 0; i < save.size() - 1; i++){
		if(nums[save[i]] > nums[save[i+1]]) return;
		str += to_string(nums[save[i]]) + " ";
	}	
	str += to_string(nums[save[save.size() - 1]]);
	res.insert(str);
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
	cin >> n;
	res.clear();
	vector<int> save, nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	Try(0, save, nums);
	for(auto it : res)
		cout << it << endl;

	return 0;
}
