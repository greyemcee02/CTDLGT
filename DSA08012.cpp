#include<bits/stdc++.h>

using namespace std;
int n;
set<int> st;
vector<int> nums;
void solve() {
	queue<int> Q;
	for(int i = 0; i <= 5; i++){
		st.insert(i);
		if(i >= 1) Q.push(i);
	}
	while(!Q.empty()){
		int k = Q.front();
		Q.pop();
		if(k > 100000) break;
		nums.push_back(k);
		vector<int> cnt(10, 0);
		int x = k;
		while(x > 0){
			cnt[x%10] = 1;
			x/=10;
		}
		for(int i = 0; i <= 5; i++){
			if(cnt[i] == 0){
				st.insert(k*10 + i);
				Q.push(k*10+i);
			}
		}
	}
}
int main() {
	solve();
	int test;
	cin >> test;
	while(test--) {
		int l, r;
		cin >> l >> r;
		vector<int>::iterator x, y;
		x = lower_bound(nums.begin(), nums.end(), l);
		y = upper_bound(nums.begin(), nums.end(), r);
		cout <<  y - x << endl;
	}
	return 0;
}
