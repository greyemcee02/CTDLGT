#include<bits/stdc++.h>

using namespace std;
int S, T;

void solve(){
	vector<int>check(20005, INT_MAX);
	queue<int> Q;
	Q.push(S);
	check[S] = 0;
	while(check[T] == INT_MAX){
		int x = Q.front();
		Q.pop();
		if(x-1 >=0 && check[x-1] == INT_MAX){
			Q.push(x-1);
			check[x-1] = check[x] + 1; 
		} 
		if(x * 2 < 20000 && x*2 > 0 && check[x*2] == INT_MAX){
			Q.push(x*2);
			check[x*2] = check[x] + 1;
		}
	}
	cout << check[T] << endl;
}

int main(){
	int test;
	cin >> test;
	while(test--){	
		cin >> S >> T;
		solve();
	}	
	return 0;
}
