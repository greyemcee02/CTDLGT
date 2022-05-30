#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		queue<int> Q;
		Q.push(9);
		while(1){
			int a = Q.front();
			Q.pop();
			if(a%n == 0){
				cout << a << endl;
				break;
			}
			else{
				Q.push(a*10);
				Q.push(a*10 + 9);
			}
		}
	}
	return 0;
}
