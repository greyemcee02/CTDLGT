#include<bits/stdc++.h>

using namespace std;

string solve(string &str) {
	int i;
	for(i = str.size() - 1; i >= 0; i--) {
		if(str[i] == '1') str[i] = '0';
		else break;
	}
	if(i >= 0) str[i] = '1';
	return str;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		string str;
		cin >> str;
		cout << solve(str) << endl;
	}
	return 0;
}

