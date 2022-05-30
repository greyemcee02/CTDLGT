#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		cout << (pow(2, n+1)) - 2 << endl;
		queue<string> Q;
		Q.push("6");
		Q.push("8");
		while(1){
			string s = Q.front();
			Q.pop();
			if(s.length() > n) break;
			else{
				cout << s << " ";
				Q.push(s+"6");
				Q.push(s + "8");
			}
		}
		cout << endl;
	}
	
	return 0;
}
