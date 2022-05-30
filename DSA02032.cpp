#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> res;

int n, x;

void Try(int i, int sum, vector<int> save, vector<int> nums) {
	for(int j = save[i - 1]; j < n; j++){
		sum += nums[j];
		save.push_back(j);
		if(sum == x){
			vector<int> tmp;
			for(int k = 1; k < save.size(); k++)
				tmp.push_back(nums[save[k]]);
			res.push_back(tmp);
		}
		else if(sum < x) Try(i + 1, sum, save, nums);
		sum -= nums[j];
		save.pop_back();
	}
}


void out(){
	if(res.size() == 0) cout << -1;
	else{
		cout << res.size() << " ";
		for(auto it : res){
			cout << "{";
			for(int i = 0; i < it.size() - 1; i++){
				cout << it[i] << " ";
			}
			cout << it[it.size() - 1] << "} ";
		}
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> x;
		res.clear();
		vector<int> nums(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		sort(nums.begin(), nums.end());
		vector<int> save;
		save.push_back(0);
		Try(1, 0, save, nums);
		out();
	}
	return 0;
}
