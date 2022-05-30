#include<bits/stdc++.h>

using namespace std;

void solve(string &str){
	int size = str.length();
	int i = size - 2;
	while(i >= 0 && str[i] >= str[i + 1]) i--;
	if(i == -1) str = "BIGGEST";
	else{
		int j = size - 1;
		while(str[j] <= str[i]) j--;
		swap(str[i], str[j]);
		int a = i + 1, b = size - 1;
		while(a < b){
			swap(str[a], str[b]);
			a++;
			b--;
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		string str;
		cin >> n >> str;
		solve(str);
		cout << n << " " << str << endl;
	}
	
	return 0;
}
