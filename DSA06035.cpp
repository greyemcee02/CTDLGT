#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int size;
		cin >> size;
		vector<int> nums(size);
		for(int i = 0; i < size; i++)
			cin >> nums[i];
		vector<int> nums1(size, 1);
		vector<int> nums2(size, 1);
		for(int i = 1; i < size; i++ ){
			if(nums[i] > nums[i - 1])
				nums1[i] = nums1[i - 1] + 1;
		}
		int res = 1;
		for(int i = size - 2; i >= 0 ; i-- ) {
			if(nums[i] > nums[ i + 1 ]) 
				nums2[i] = nums2[i + 1] + 1;
		}
		for(int i = 0; i < size; i++){
			res = max(res, nums2[i] + nums1[i] - 1);
		}
		cout << res << endl;
	} 
	return 0;
}
