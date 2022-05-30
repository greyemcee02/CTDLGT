#include<bits/stdc++.h>

using namespace std;
string str;
vector<int> check;
void Try(string &s, int i) {
	for(int j = 0; j < str.length(); j++) {
		if(check[j] == 0) {
			check[j] = 1;
			s[i] = str[j];
			if( i == str.length() - 1) cout << s <<" ";
			else Try(s, i + 1);
			check[j] = 0;
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> str;
		for(int i = 0; i < str.length(); i++)
			check.push_back(0);
		string s = str;
		Try(s, 0);
		cout << endl;
	}
	return 0;
}
