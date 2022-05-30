#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		queue<long long> Q;
		Q.push(1);
		while(1){
			long long a = Q.front();
			Q.pop();
			if(a%n == 0){
				cout << a << endl;
				break;
			}
			else{
				Q.push(a*10);
				Q.push(a*10+1);
			}
		}
	}
	return 0;
}

