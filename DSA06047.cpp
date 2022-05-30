#include<bits/stdc++.h>

using namespace std;

int search(vector<int> nums, int left, int right, long long k) {
	if(left <= right){
		int mid = (left + right)/2;
		if(k == nums[mid]) return 1;
		else if(k < nums[mid]) return search(nums, left, mid - 1, k);
		else return search(nums, mid + 1, right, k);
	}
	return -1;
}

int solve(vector<int> nums, int size) {
	for(int i = 0; i < size - 2; i++) {
		for(int j = i + 1; j < size - 1; j++){
			long long sum = (long long)nums[i] * nums[i];
			sum += (long long)nums[j] * nums[j];
			long long tmp = sqrt(sum);
			if(tmp * tmp == sum){
				int p = j + 1;
				if(tmp == nums[p]) return 1;
				else if(tmp < nums[p] || tmp > nums[size - 1]);
				else{
					int s = search(nums, p, size - 1, tmp);
					if(s == 1) return 1;
				}
			}
		}
	}
	return -1;
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
		sort(nums.begin(), nums.end());
		int s = solve(nums, size);
		if(s == 1) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}

