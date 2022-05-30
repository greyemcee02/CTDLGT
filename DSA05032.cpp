#include<bits/stdc++.h>

using namespace std;

void DP(string &str){
	int sz = str.length();
	string str1;
	for(auto it : str){
		str1 = it + str1;
	}
	vector<vector<int>> F(sz + 1, vector<int>(sz + 1, 0));
	for(int i = 1; i <= sz; i++){
		for(int j = 1; j <= sz; j++){
			if(str[i-1] == str1[j-1]){
				F[i][j] = F[i-1][j-1] + 1;
			}
			else F[i][j] = max(F[i-1][j], F[i][j-1]);
		}
	}
	cout << sz - F[sz][sz] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		DP(str);
	}
	return 0;
}
