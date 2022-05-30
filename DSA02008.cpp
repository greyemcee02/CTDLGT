#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<vector<int>> nums;
vector<vector<int>> res;
vector<int> save;
vector<int> check(101, 0);
void Try(int i, int s) {
	for(int j = 0; j < n; j++){
		if(check[j] == 0){
			check[j] = 1;
			save.push_back(j + 1);
			s += nums[i][j];
			if(i == n - 1){
				if(s == k) res.push_back(save);
			}
			else Try(i + 1, s);
			save.pop_back();
			s -= nums[i][j];
			check[j] = 0;
		}
	}
}

void in(){
	cout << res.size() << endl;
	for(auto it : res){
		for(auto i : it)
			cout << i << " ";
		cout << endl;
	}
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		vector<int> num(n);
		for(int j = 0; j < n; j++){
			cin >> num[j];
		}
		nums.push_back(num);
	}
	Try(0, 0);
	in();
	return 0;
}
