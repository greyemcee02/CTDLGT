#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> nums(8, vector<int>(8, 0));
vector<int> xuoi(15, 0), nguoc(15, 0), check(8, 0);
vector<vector<int>> res;
vector<int> save(8, 0);
void Try(int i){
	for(int j = 0; j < 8; j++){
		if(!check[j] && !xuoi[i - j + 7] && !nguoc[i + j]){
			check[j] = 1;
			xuoi[i - j + 7] = 1;
			nguoc[i + j] = 1;
			save[i] = j;
			if(i == 7){
				res.push_back(save);
			}
			else Try(i + 1);
			check[j] = 0;
			xuoi[i - j + 7] = 0;
			nguoc[i + j] = 0;
		}
	}
}

int main() {
	Try(0);
	int test;
	cin >> test;
	while(test--){
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++)
				cin >> nums[i][j];
		}
		int kq = INT_MIN;
		for(auto it : res){
			int tmp = 0;
			for(int i = 0; i < it.size(); i++){
				tmp += nums[i][it[i]];
			}
			kq = max(kq, tmp);
		}
		cout << kq << endl;
	}
	return 0;
}
