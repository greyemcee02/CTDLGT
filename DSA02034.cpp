#include<bits/stdc++.h>

using namespace std;
char c;
int n;

bool check(vector<int> nums){
	for(int i = 1; i < nums.size(); i++){
		if(abs(nums[i] - nums[i-1]) == 1) return false;
	}
	return true;
}

int main(){
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			nums[i] = i + 1;
			while(next_permutation(nums.begin(), nums.end())){
			if(check(nums)){
				for(auto it : nums)
					cout << it;
				cout << endl;
			}
		}
	}
	
	return 0;
}
