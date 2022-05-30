#include<bits/stdc++.h>

using namespace std;

void solve(queue<int> &Q, int tv){
	switch(tv){
		case 1:
			cout << Q.size() << endl;
			break;
		case 2:
			cout << (Q.empty()?"YES":"NO") << endl;
			break;
		case 3:
			int k;
			cin >> k;
			Q.push(k);
			break;
		case 4:
			if(!Q.empty()){
				Q.pop();
			}	
			break;
		case 5:
			if(Q.empty()) cout << -1 << endl;
			else cout << Q.front() << endl;
			break;
		case 6:
			if(Q.empty()) cout << -1 << endl;
			else cout << Q.back() << endl;
			break;
			
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		queue<int> Q;
		int n, tv;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> tv;
			solve(Q, tv);
		}
	}
	return 0;
}
