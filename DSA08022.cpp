#include<bits/stdc++.h>

using namespace std;
vector<int> nums;
int n;
int s;

void out(vector<int> nums, int p1, int p2 = -1){
	for(int i = n - 1; i >= 0; i--){
		if(i!= p1 && i != p2)
			cout << nums[i];
	}
}

void solve(){
	if(s%3 == 0){
		for(int i = n - 1; i >= 0; i--)
			cout << nums[i];
		return;
	}
	else if(s%3 == 1){
		int p2_0 = -1, p2_1 = -1;
		for(int i = 0; i < n; i++){
			if(nums[i] % 3 == 1){
				out(nums, i);
				return;
			}
			if(nums[i] % 3 == 2){
				if(p2_0 == -1)
					p2_0 = i;
				else if(p2_1 == -1)
					p2_1 = i;
			}
		}
		if(p2_0 != -1 && p2_1 != -1 && n > 2){
			out(nums, p2_0, p2_1);
			return;
		}
	}
	else{
		int p1_0 = -1, p1_1 = -1;
		for(int i = 0; i < n; i++){
			if(nums[i] % 3 == 2){
				out(nums, i);
				return;
			}
			if(nums[i] % 3 == 1){
				if(p1_0 == -1)
					p1_0 = i;
				else if(p1_1 == -1)
					p1_1 = i;
			}
		}
		if(p1_0 != -1 && p1_1 != -1 && n > 2){
			out(nums, p1_0, p1_1);
			return;
		}
	}
	cout << -1; 
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		nums.resize(n);
		s = 0;
		for(int i = 0; i < n; i++){
			cin >> nums[i];
			s += nums[i];
		}	
		sort(nums.begin(), nums.end());
		solve();
		cout << endl;
	}
	return 0;
}

