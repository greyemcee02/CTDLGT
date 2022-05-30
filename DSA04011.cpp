#include<bits/stdc++.h>

using namespace std;

vector<int> save(31, 0);

void solve() {
	save[0] = 1;
	for(int i = 1; i <= 30; i++)
		save[i] = 2 * save[i-1];
}

long long result(string str1, string str2){
	int a = 0, b = 0;
	for(int i = 0; i < str1.length(); i++)
		a += (str1[i] - '0') * (save[str1.length() - 1 - i]);
	for(int i = 0; i < str2.length(); i++)
		b += (str2[i] - '0') * (save[str2.length() - 1 - i]);
	return (long long)a*b;
}

int main() {
	solve();
	int test;
	cin >> test;
	while(test--){
		string str1, str2;
		cin >> str1 >> str2;
		cout << result(str1, str2) << endl;
	}	
	return 0;
}
