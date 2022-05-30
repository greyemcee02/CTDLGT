#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int size;
		cin >> size;
		vector<int> nums(size);
		vector<vector<int>> res;
		for(int i = 0; i < size; i++)
			cin >> nums[i];
		res.push_back(nums);
		for(int i = 1; i < size; i++) {
			vector<int> tmp(size - i);
			for(int j = 0; j < size - i; j++){
				nums[j] = nums[j] + nums[j+1];
				tmp[j] = nums[j]; 
			}
			res.push_back(tmp);
		}
		for(auto it : res){
			cout << "[";
			for(int i = 0; i < it.size() - 1; i++){
				cout << it[i] << " ";
			}
			cout << it[it.size() - 1] << "]" << endl;
		}
	}
	return 0;
}
