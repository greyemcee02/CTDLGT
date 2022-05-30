#include<bits/stdc++.h>

using namespace std;
int n;

void solve(){
	queue<string> Q;
	Q.push("4");
	Q.push("5");
	while(n--){
		string str = Q.front();
		Q.pop();
		cout << str;
		for(int i = str.length() - 1; i >= 0; i--)
			cout << str[i];
		cout << " ";
		Q.push(str+"4");
		Q.push(str + "5");
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;	
		solve();	
	}
	return 0;
}
