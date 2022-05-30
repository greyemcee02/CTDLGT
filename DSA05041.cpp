#include<bits/stdc++.h>

using namespace std;

void DP(string &str){
	string str1;
	for(auto it : str){
		str1 = it + str1;
	}
	int sz = str.length();
	vector<vector<int>> QHD(sz + 1, vector<int>(sz + 1, 0));
	for(int i = 1; i <= sz; i++){
		for(int j = 1; j <= sz; j++){
			if(str[i-1] == str1[j-1])
				QHD[i][j] = QHD[i-1][j-1] + 1;
			else
				QHD[i][j] = max(QHD[i-1][j], QHD[i][j-1]);
		}
	}
	cout << sz - QHD[sz][sz] << endl;
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
