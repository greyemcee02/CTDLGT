#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, cnt = 0;
		cin >> n;
		queue<string> Q;
		Q.push("1");
		while(1){
			if(cnt >= n) break;
			else{
				string str = Q.front();
				Q.pop();
				cout << str << " ";
				cnt++;
				Q.push(str+"0");
				Q.push(str+"1");
			}
		}
		cout << endl;
	}
	return 0;
}
