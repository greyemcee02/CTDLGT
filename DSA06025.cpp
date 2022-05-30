#include<bits/stdc++.h>

using namespace std;

void Sort(vector<int> &nums){
	int cnt = 0;
	for(int i = 0; i < nums.size(); i++){
		cout << "Buoc " << cnt++ << ": ";
		int p = nums[i], j;
		for( j = i - 1; j >= 0; j--){
			if(p < nums[j]){
				nums[j + 1] = nums[j]; 
			}
			else break;
		}
		if(j == -1) nums[0] = p;
		else
			nums[j+1] = p;
		for(int j = 0; j <= i; j++){
			cout << nums[j] << " ";
		}
		cout << endl;
		
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
