#include<bits/stdc++.h>

using namespace std;

void Sort(vector<int> &nums){
	int cnt = 1;
	for(int i = 0; i < nums.size(); i++){
		bool ok = true;
		cout << "Buoc " << cnt++ << ": ";
		for(int j = i + 1; j < nums.size(); j++){
			if(nums[i] > nums[j])
				swap(nums[i], nums[j]);
		}
		for(int j = 0; j < nums.size(); j++){
			if(j < nums.size() - 1){
				if(nums[j] > nums[j + 1]) ok = false;
			}
			cout << nums[j] << " ";
		}
		cout << endl;
		if(ok) break;
	}
	
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n ; i++){
		cin >> nums[i];
	}
	Sort(nums);	
	return 0;
}
