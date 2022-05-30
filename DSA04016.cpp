#include<bits/stdc++.h>

using namespace std;

void nhap(vector<int> &nums){
	for(auto &it : nums)
		cin >> it;
}

int solve(vector<int> nums1, vector<int> nums2, int n, int m, int k){
	int i =0, j = 0, cnt = 0, res;
	while(i < n && j < m){
		cnt++;
		if(nums1[i] <= nums2[j]){
			if(cnt == k){		
				return nums1[i];
			}
			i++;
		}
		else{
			if(cnt == k){		
				return nums2[j];
			}
			j++;
		}
	}
	while(i < n){
		cnt++;
		if(cnt == k){		
				return nums1[i];
		}
		i++;
	}
	while(j < m){
		cnt++;
		if(cnt == k){		
			return nums2[j];
		}
		j++;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> nums1(n);
		vector<int> nums2(m);
		nhap(nums1);
		nhap(nums2);
		cout << solve(nums1, nums2, n, m, k) << endl;
	}
	return 0;
}
