#include<bits/stdc++.h>

using namespace std;
int n;

void solve(vector<int> nums, multiset<int> st){
	int cnt = 0;
	while(nums.size() > 0){
		int k = nums[nums.size() - 1];
		nums.pop_back();
		multiset<int>::iterator x = st.lower_bound(k*2);
		if(x == st.end()) st.insert(k);
		else{
			cnt++;
			st.erase(x);
		}
	}
	cnt += st.size();
	cout << cnt << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		vector<int> nums;
		multiset<int> st;
		int tmp;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			nums.push_back(tmp);
		}	
		sort(nums.begin(), nums.end());
		while(nums.size() > n/2){
			tmp = nums[nums.size() - 1];
			nums.pop_back();
			st.insert(tmp);
		}
		solve(nums, st);
	}
	
	return 0;
}
