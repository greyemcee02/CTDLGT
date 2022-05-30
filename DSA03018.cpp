#include<bits/stdc++.h>

using namespace std;

void solve(int n){
	string res;
	if(n%7 == 0){
		while(n > 0){
			cout << 7;
			n-=7;
		}
		cout << endl;
		return;
	}
	int a = n;
	int mn = n;
	while(a >= 7){
		a-=7;
		if(a%4 ==0) mn = min(mn, a);
	}
	if(mn  % 4!=0){
		cout << -1 << endl;
	}
	else{
		int s = n - mn;
		while(mn>0){
			cout << 4;
			mn-=4;
		}
		while(s >0){
			cout << 7;
			s-=7;
		}
		cout << endl;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		solve(n);
	}
	return 0;
}
