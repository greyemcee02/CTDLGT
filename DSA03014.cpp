#include<bits/stdc++.h>

using namespace std;
vector<long long> nums;
long long n;

int search(long long n, int l, int r){
	while(l < r){
		int m = (l + r)/2;
		if(nums[m] >= n){
			r = m;
		}
		else l = m + 1;
	}
	return l;
}

bool check(long long num1, long long num2){
	if(num1 > num2) return false;
	if(num1 == num2) return true;
	while(num1 > 0 && num2 > 0){
		int x = num1%10;
		int y = num2%10;
		if(x != y) num2/=10;
		else {
			num1/=10;
			num2/=10;
		}
	}
	if(num1 == 0) return true;
	return false;
}

void solve(){
	int k = search(n, 0, nums.size() - 1);
	while(k > 0){
		if(check(nums[k], n)){
			cout << nums[k] << endl;
			return;
		}
		k--;
	}
	cout << -1 << endl;
}

int main() {
	for(int i = 0; i <= 999999; i++){
		nums.push_back((long long)(pow(i, 3)));
	}
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		solve();
	}
	return 0;
}
