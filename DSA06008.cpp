#include<bits/stdc++.h>

using namespace std;

long long solve(vector<int> nums1, vector<int> &nums2){
	long long res = 0;
	vector<int> count(6, 0);
	for(int i = 0; i < nums2.size(); i++){
		if(nums2[i] < 5) count[nums2[i]]++;
	}
	sort(nums2.begin(), nums2.end());
	for(int i = 0; i < nums1.size(); i++) {
		if(nums1[i] == 0){
			continue;
		}
		else if(nums1[i] == 1){
			res += count[0];
		}
		else {
			std::vector<int> :: iterator idx = upper_bound(nums2.begin(), nums2.end(), nums1[i]);
			res += nums2.end() - idx;
			res += count[0] ;
			res += count[1];
			if(nums1[i] == 3) res += (count[2]);
			if(nums1[i] == 2) res -= (count[3] + count[4]);
		}
	}
	return res;
}



int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> nums1(n), nums2(m);
		for(int i = 0; i < n; i++)
			cin >> nums1[i];
		for(int j = 0; j < m; j++)
			cin >> nums2[j];
		cout << solve(nums1, nums2) << endl;
	}
	return 0;
}
