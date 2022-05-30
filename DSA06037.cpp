#include<bits/stdc++.h>

using namespace std;

vector<int> res;

void solve(vector<int> maxLeft, vector<int> minRight, int n){
	for(int i = 0; i < n - 1; i++){
		if(maxLeft[i] <= minRight[i + 1] )
			res.push_back(i + 1);
	}
	
}

void out(){
	cout << res.size() << endl;
	for(auto it : res)
		cout << it << " ";
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		res.clear();
		vector<int> nums(n);
		vector<int> maxLeft(n, 0), minRight(n);
		cin >> nums[0];
		maxLeft[0] = nums[0];
		for(int i = 1; i < n; i++){
			cin >> nums[i];
			maxLeft[i] = max(maxLeft[i - 1], nums[i]);
		}
		minRight[n - 1] = nums[n - 1];
		for(int i = n - 2; i >= 0; i--)
			minRight[i] = min(minRight[i + 1], nums[i]);
		solve(maxLeft, minRight, n);
		out();	
	}
	return 0;
}



