#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int size;
		cin >> size;
		vector<int> nums(size);
		stack<vector<int>> res;
		for(int i = 0; i < size; i++)
			cin >> nums[i];
		res.push(nums);
		for(int i = 1; i < size; i++) {
			vector<int> tmp(size - i);
			for(int j = 0; j < size - i; j++){
				nums[j] = nums[j] + nums[j+1];
				tmp[j] = nums[j]; 
			}
			res.push(tmp);
		}
		while(!res.empty()){
			vector<int> tmp = res.top();
			res.pop();
			cout << "[";
			for(int i = 0; i < tmp.size() - 1; i++){
				cout << tmp[i] << " ";
			}
			cout << tmp[tmp.size() - 1] << "] ";
		}
		cout << endl;
	}
	return 0;
}
