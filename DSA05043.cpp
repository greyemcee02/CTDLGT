#include<bits/stdc++.h>

using namespace std;

void DP(string &str){
	int sz = str.length();
	int res = 1;
	vector<vector<int>> F(sz + 1, vector<int>(sz + 1, 0));
	for(int i = 1; i <= sz; i++){
		for(int j = 0; j<= sz - i; j++){
			if(str[j] == str[i + j - 1]){
				if(i <= 2){
					F[i + j - 1][j] = 1;
					res = max(res, i);
				}
				else if(F[i + j - 2][j + 1]){
					F[i + j - 1][j] = 1;
					res = max(res, i);
				}
			}
		}
	}
	cout << res << endl;
	

}

int main() {
	int test;
	cin >> test;
	while(test--) {
		string str;
		cin >> str;
		DP(str);
	}
	return 0;
}
