#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int x;

void merge(int left, int mid, int right,vector<pair<int, int>> &nums){
	
	vector<pair<int, int>> s1;
	vector<pair<int, int>> s2;
	for(int i = left; i <= mid; i++)
		s1.push_back(nums[i]);
	for(int j = mid + 1; j <= right; j++)
		s2.push_back(nums[j]);
	int p1 = 0, p2 = 0, p = left;
	while(p1 < s1.size() && p2 < s2.size()){
		if(abs(x - s1[p1].second) < abs(x - s2[p2].second)){
			nums[p] = s1[p1];
			p1++;
		}
		else if(abs(x - s1[p1].second) > abs(x - s2[p2].second)){
			nums[p] = s2[p2];
			p2++;
		}
		else {
			if(s1[p1].first < s2[p2].first){
				nums[p] = s1[p1];
				p1++;
			}
			else{
				nums[p] = s2[p2];
				p2++;
			}
		}
		p++;
	}
	while(p1 < s1.size()){
		nums[p] = s1[p1];
		p++;
		p1++;
	}
	while(p2 < s2.size()){
		nums[p] = s2[p2];
			p++;
			p2++;
	}
}

void mSort(int left, int right, vector<pair<int, int>> &nums) {
	if(left < right){
		int mid = (left + right)/2;
		mSort(left, mid, nums);
		mSort(mid + 1, right, nums);
		merge(left, mid, right, nums);
	}
	
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n >> x;
		vector<pair<int, int>> nums(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i].second;
			nums[i].first = i;
		}
		mSort(0, n - 1, nums);
		for(auto it : nums)
			cout << it.second << " ";
		cout << endl;
	}
	return 0;
}
