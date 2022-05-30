#include<bits/stdc++.h>

using namespace std;
int n;
long long res;
void merge(int l, int mid, int r, vector<int> &nums){
	vector<int> lf, rt;
	for(int i = l; i <= mid; i++)
		lf.push_back(nums[i]);
	for(int i = mid + 1; i <= r; i++)
		rt.push_back(nums[i]);
	int p1 = 0, p2 = 0, curr = l;
	while(p1 < lf.size() && p2 < rt.size()){
		if(lf[p1] > rt[p2]){
			res+=(rt.size() - p2);
			nums[curr] = lf[p1];
			curr++;
			p1++;
		}
		else{
			nums[curr] = rt[p2];
			curr++;
			p2++;
		}
	}
	while(p1 < lf.size()){
		nums[curr] = lf[p1];
		curr++;
		p1++;
	}
	while(p2 < rt.size()){
		nums[curr] = rt[p2];
		curr++;
		p2++;
	}
}

void mergeSort(int l, int r, vector<int> &nums){
	if(l < r){
		int mid = (l + r)/2;
		mergeSort(l, mid, nums);
		mergeSort(mid + 1, r, nums);
		merge(l, mid, r, nums);
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		res = 0;
		vector<int> nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];	
		mergeSort(0, nums.size() - 1, nums);
		cout << res << endl;
	}
	return 0;
}
