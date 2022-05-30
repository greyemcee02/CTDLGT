#include<bits/stdc++.h>

using namespace std;
int n, tmp;
vector<int> nums;
vector<int> check;
vector<int> save;
void Try(int i){
	for(int j = 0; j < n; j++){
		if(!check[j]){
			check[j] = 1;
			save.push_back(nums[j]);
			if(i == n - 1){
				for(auto it : save)
					cout << it << " ";
				cout << endl;
			}
			else Try(i+1);
			check[j] = 0;
			save.pop_back();
		}
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		nums.push_back(tmp);
		check.push_back(0);
	}
	sort(nums.begin(), nums.end());
	Try(0);
	return 0;
}

