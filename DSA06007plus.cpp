#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> nums) {
	int p1 = 0, p2 = nums.size() - 1;
	int start, end;
	int mn = nums[p2], mx = nums[p1];
	while(p1 < nums.size()){
		if(mx > nums[p1]) end = p1;
		mx = max(mx, nums[p1]);
		p1++;
	}
	while(p2 > 0){
		if(mn < nums[p2]) start = p2;
		mn = min(mn, nums[p2]);
		p2--;
	}
	cout << start + 1 << " " << end + 1 << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int size;
		cin >> size;
		vector<int> nums(size);
		for(int i = 0; i < size; i++)
			cin >> nums[i];
		solve(nums);
	}	
	return 0;
}

