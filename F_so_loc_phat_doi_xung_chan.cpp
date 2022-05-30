#include<bits/stdc++.h>

using namespace std;
int n;

void solve(){
	queue<string> Q;
	Q.push("6");
	Q.push("8");
	while(n--){
		string str = Q.front();
		Q.pop();
		cout << str;
		for(int i = str.length() - 1; i >= 0; i--)
			cout << str[i];
		cout << " ";
		Q.push(str+"6");
		Q.push(str + "8");
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
