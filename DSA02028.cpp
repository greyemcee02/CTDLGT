#include<bits/stdc++.h>

using namespace std;
int n, k, sum = 0, tmp, res = 0;
vector<int> nums;
bool ok = false;
void Try(int i, int s, int cnt){
	if(cnt == k - 1){
		res++;
		return;
	}
	for(int j = i; j <= n - k + cnt; j++){
		s+= nums[j];
		if(s == sum/k){
			Try(j + 1, 0, cnt + 1);
		}
	}
	
}

int count(){
	if(sum%k != 0|| n < k) return 0;
	Try(0, 0, 0);
	return res;
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		sum += tmp;
		nums.push_back(tmp);
	}
	cout << count() << endl;
	return 0;
}
