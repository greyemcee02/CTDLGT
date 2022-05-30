#include<bits/stdc++.h>

using namespace std;
int n;
void in(vector<int> nums){
	cout << '(';
	for(int j = 0; j < nums.size() - 1; j++) 
		cout << nums[j] << " ";
	cout << nums[nums.size() - 1];
	cout << ") ";
}

void Try(int a, int s, vector<int> nums){
	for(int i = a; i >= 1; i--){
		if(s + i <= n){
			s += i;
			nums.push_back(i);
			if(s == n){
				in(nums);
			} 
			else Try(i, s, nums);
			s -= i;
			nums.pop_back();
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<int> nums;
		Try(n, 0, nums);
		cout << endl;
	}
	
	
	return 0;
}
