#include<bits/stdc++.h>

using namespace std;
long long n, sz;
string s;

void solve() {
	long long s1 = sz;
	while(1){// nhan 2 den chet
		s1 *= 2;
		if(s1 >= n) break;
	}
	while(n > sz){
		if(n <= s1/2);//giu nguyen
		else{
			if(n == s1/2 + 1){
				n = s1/2;
			}
			else n = n - s1/2 - 1;
		}
		s1/=2;
	}
	cout << s[n-1] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> s >> n;
		sz = s.size();
		solve();
	}
	return 0;
}

