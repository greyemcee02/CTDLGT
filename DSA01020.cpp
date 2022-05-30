#include<bits/stdc++.h>

using namespace std;

void solve(string str) {
	int i = str.length() - 1;
	while(i >= 0 && str[i] == '0'){
		str[i] = '1';
		i--;	
	}
	if(i >= 0) str[i] = '0';
	cout << str << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		string str;
		cin >> str;
		solve(str);
	}
	return 0;
}

