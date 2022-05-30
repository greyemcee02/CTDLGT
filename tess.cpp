#include<bits/stdc++.h>

using namespace std;
int n, k, sum;

bool Try(map<int, int> &nums, map<int, int> :: iterator it, int cnt, int s ){
	if(cnt == k) return true;
	for(auto i = it; i != nums.end(); i++){
		if((*i).second) {
			s += (*i).first;
			(*i).second--;
			if(s == sum){
				if(Try(nums, nums.begin(), cnt + 1, 0)) return true;
			}
			else if(s < sum){
				if(Try(nums, i, cnt, s)) return true;
			}
			s -= (*i).first;
			(*i).second++;
		}
	}
	return false;
}

bool solve(map<int, int> &nums) {
	if(k == 1) return true;
	if(k > n) return false;
	if(sum % k != 0) return false;
	sum /= k;
	return Try(nums, nums.begin(), 0, 0);
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int tmp;
		sum = 0;
		cin >> n >> k;
		map<int, int> nums;
		for(int i = 0; i  < n; i++){
			cin >> tmp;
			sum += tmp;
			nums[tmp]++;
		}
		if(solve(nums)) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
