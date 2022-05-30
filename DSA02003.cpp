#include<bits/stdc++.h>

using namespace std;
bool ok;
int size;
vector<int> hang = {1, 0}, cot = {0, 1};
void Try(vector<vector<int>> nums, string res, int h, int c) {
	for(int j = 0; j <= 1; j++) {
		if(nums[h + hang[j]][c + cot[j]]){
			if(j == 0) res += 'D';
			else res += 'R';
			if(h + hang[j] == size - 1 && c + cot[j] == size - 1){
				cout << res << " ";
				ok = true;
			}
			else Try(nums, res, h + hang[j], c + cot[j]);
			res.pop_back();
		} 
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> size;
		vector<vector<int>> nums;
		vector<int> num(size + 1);
		num[size] = 0;
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				cin >> num[j];
			}
			nums.push_back(num);
		}
		if(nums[0][0] == 0){
			cout << -1 << endl;
			continue;
		}
		for(int i = 0; i < size; i++)
			num[i] = 0;
		nums.push_back(num);
		ok = false;
		string res;
		Try(nums, res, 0, 0);
		if(ok == false) cout << "-1";
		cout << endl;
	}
	return 0;
}
