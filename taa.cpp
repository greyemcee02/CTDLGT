#include<bits/stdc++.h>

using namespace std;
int n, res = 0;
vector<int> nums(100000);
vector<pair<int, int>> num;
vector<int> cnt(100000);

void merge(int l, int mid, int r){
	vector<pair<int, int>> p1, p2;
	for(i = l; i <= mid; i++){
		p1.push_back(num[i]);
	}
	for(i = mid + 1; i <= r; i++){
		p2.push_back(num[i]);
	}
	int k1 = 0, k2 = 0, k = l;
	while(k1 < p1.size() && k2 < p2.size()){
		if(p1[k1].first > p2[k2].first){
			res += cnt[p2[k2].second] - cnt[p1[k1].second];
			num[k] = p1[k1];
			k++; k1++;
		}
		else{
			num[k] = p2[k2];
			k++; k2++;
		}
	}
	while(k1 < pq.size()){
		
	}
}

void mergeSort(int l, int r){
	if(l < r){
		int mid = (l + r)/2;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		merge(l, mid, r);
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
		if(nums[i]%2 == 0)
			num.push_back({nums[i], i});
	}
	if(nums[0] % 2 != 0) cnt[0] = 1;
	for(int i = 1; i < n; i++){
		cnt[i] = cnt[i-1];
		if(nums[i]%2 != 0)
			cnt[i]++;
	}
		
	
	return 0;
}
