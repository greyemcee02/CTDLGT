#include<bits/stdc++.h>

using namespace std;
int n;

void solve(vector<pair<int, int>> &nums){
	int res = 1;
	vector<int> H(n);
	H[0] = 0;
	for(int i = 2; i < n; i++){
		if(nums[i].first <= nums[H[0]].first && nums[i].second <= nums[H[0]].second){
			H[0] = i;
		}
		else if(nums[i].first == nums[H[res]].first && nums[i].second <= nums[H[res]].second){
			H[res] = i;
		}
		else if(nums[i].first > nums[H[res]].first && nums[i].second > nums[H[res]].second){
			res++;
			H[res] = i;
		}
		else if(nums[i].first > nums[H[0]].first && nums[i].second > nums[H[0]].second){
			if(nums[i].first < nums[H[res]].first && nums[i].second < nums[H[res]].second){
				
			}
		}
	}
}

int main() {
	cin >> n;
	vector<pair<int, int>> nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i].first >> nums[i].second;
	solve(nums);	
	return 0;
}
