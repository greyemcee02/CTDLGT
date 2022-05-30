#include<bits/stdc++.h>


using namespace std;

vector<int> hang = {1, 0, 0, -1}, cot = {0, -1, 1, 0};
string s = "DLRU";
int size;
bool ok;
vector<vector<int>> nums;
void Try(int h, int c, string str) {
	for(int j = 0; j < 4; j++) {
		if(nums[h + hang[j]][c + cot[j]]){
			str.push_back(s[j]);
			nums[h][c] = 0;
			if(h + hang[j] == size && c + cot[j] == size){
				ok = true;
				cout << str << " ";
			}
			else Try(h + hang[j], c + cot[j], str);
			str.pop_back();
			nums[h][c] = 1;
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> size;
		nums.clear();
		ok = false;
		for(int i = 0; i <= size  + 1; i++) {
			vector<int> tmp(size + 2, 0);
			if(i == 0 || i == size + 1);
			else{
				for(int j = 1; j <= size ; j++){
					cin >> tmp[j];
				}
			}
			nums.push_back(tmp);
		}
		Try(1, 1, "");
		if(ok == false)
			cout << -1 ;
		cout << endl;
		
	}
	return 0;
}

