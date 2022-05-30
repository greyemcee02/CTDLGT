#include<bits/stdc++.h>

using namespace std;
int n;
//set<string> res;

void Try(int i, int sum, vector<int> nums, vector<int> save){
	for(int j = 0; j <= 1; j++){
		if(j){
			sum += nums[i];
			save.push_back(nums[i]);
		}
		if(i == n - 1){
			if(sum % 2 != 0) {
				for(auto it : save)
					cout << it  << " ";
				cout << endl;
			}
		}
		else Try(i + 1, sum, nums, save);
		if(j){
			sum -= nums[i];
			save.pop_back();
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		sort(nums.begin(), nums.end(), greater<int>());
		vector<int> save;
		Try(0, 0, nums, save);
		
	}
	return 0;
}
