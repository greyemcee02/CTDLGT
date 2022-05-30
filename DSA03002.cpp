#include<bits/stdc++.h>

using namespace std;
int mn = 0, mx = 0;
void solve(string str){
	string s1, s2;
	for(int i = 0; i < str.length(); i++){
		s1.push_back(str[i]);
		s2.push_back(str[i]);
		if(str[i] == '6'){
			s1[i] = '5';
		} 
		if(str[i] == '5'){
			s2[i] = '6';
		}
	}
	istringstream is1(s1);
	int a;
	is1 >> a;
	mn += a;
	istringstream is2(s2);
	int b;
	is2 >> b;
	mx += b;
}

int main() {
	string a, b;
	cin >> a >> b;
	solve(a);
	solve(b);
	cout << mn << " " << mx;
	return 0;
}
