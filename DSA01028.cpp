#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<int> nums;

void Try(int i, int a, vector<int> save){
	for(int j = a + 1; j <= n - k + i; j++){
		save.push_back(nums[j - 1]);
		if(i == k){
			for(auto it : save)
				cout << it << " ";
			cout << endl;
		}
		else Try(i + 1, j, save);
		save.pop_back();
	}
}

int main() {
	cin >> n >> k;
	set<int> st;
	int tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		st.insert(tmp);
	}
	for(auto it : st){
		nums.push_back(it);
	}
	n = nums.size();
	vector<int> save;
	Try(1, 0, save);
	return 0;
}
