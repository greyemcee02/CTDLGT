#include<bits/stdc++.h>

using namespace std;
int n, s;

void solve(){
	
	if(s == 0){
		if(n == 1) cout << 0 << " " << 0 << endl;
		else cout << -1 << " " << -1 << endl;
	}
	else if(n * 9 < s) cout << -1 << " " << -1 << endl;
	else{
		int n1 = s, n2 = s - 1;
		string mx, mn;
		while(n1 > 9){
			mx.push_back('9');
			n1-=9;
		}
		mx.push_back((n1 +'0'));
		while(mx.length() < n) mx.push_back('0');
		
		while(n2 > 9){
			mn.push_back('9');
			n2-=9;
		}
		mn = (char)(n2 +'0') + mn;
		while(mn.length() < n)
			mn = '0' + mn;
		mn[0]++;
		cout << mn << " " << mx << endl;
	}
	
}

int main() {
	cin >> n >> s;
	solve();
	return 0;
}
