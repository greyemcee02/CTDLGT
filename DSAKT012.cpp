#include<bits/stdc++.h>

using namespace std;
int n, s, res;
vector<int> nums;
vector<int> check(n);

void Try(int i, int cnt1, long long sum) {
	for(int j = 1; j >= 0; j--){
		if(j){
			sum += nums[i];
			cnt1++;
		}	
		if(sum >= s || i == n - 1){
			if(sum == s){
				res = min(res, cnt1);
			} 
		} 
		else if(sum < s) Try(i + 1, cnt1, sum);
		if(j){
			sum -= nums[i];
			cnt1--;
		}
	}
}

int main() {
	cin >> n >> s;
	res = n + 1;
	int tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}
	sort(nums.begin(), nums.end(), greater<int>());
	Try(0, 0, 0);
	if(res == n + 1)
	cout << - 1 << endl;
	else
	cout << res << endl;
	return 0;
}


