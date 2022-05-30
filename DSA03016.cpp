#include<bits/stdc++.h>

using namespace std;
int s, d;

string solve(){
	if(9 * d < s) return "-1";
	string res;
	s-=1;
	while(s>=9){
		s-=9;
		res.push_back('9');
	}
	char chr = (s + '0');
	res = chr + res;
	while(res.length() < d)
		res = "0" + res;
	res[0] += 1;
	return res;
	
}
int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> s >> d;
		cout << solve() << endl;
	}
	return 0;
}
