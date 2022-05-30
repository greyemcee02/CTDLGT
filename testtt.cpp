#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> nums;
vector<int> le;
long long res;

void merge(int l, int mid, int r, vector<int> &num){
	vector<int> left, right;
	for(int i = l; i <= mid; i++)
		left.push_back(num[i]);
	for(int i = mid + 1; i <= r; i++)
		right.push_back(num[i]);
	int p = l, p1 = 0, p2 = 0;
	while(p1 < left.size() && p2 < right.size()){
		if(left[p1] < right[p2]){
			if(left[p1] % 2 == 0 && right[p2] % 2 == 0){
				int k1 = binary_search(nums.begin(), nums.end(), left[p1]);
				int k2 = binary_search(nums.begin(), nums.end(), right[p2]);
				res += le[k2] - le[k1];
			}
		}
	}
}

void mergeSort(int l, int r, vector<int> &num){
	if(l < r){
		int mid = (l + r)/2;
		mergeSort(l, mid, num);
		mergeSort(mid+1, r, num);
		merge(l, mid, r, num);
	}
}


int main() {
	cin >> n;
	res = 0;
	nums.resize(n);
	le.resize(n , 0);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	if(nums[0] %2 != 0)
		le[0] = 1;
	for(int i = 1; i <= n; i++){
		le[i] = le[i-1];
		if(nums[i]%2 != 0)
			le[i]++;		
	}
	return 0;
}
