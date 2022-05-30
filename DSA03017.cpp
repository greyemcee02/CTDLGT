#include<bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

long long solve(priority_queue<int> Q){
	long long res = 0;
	while(!Q.empty()){
		int a = Q.top();
		Q.pop();
		res += (long long)a*a;
	}
	return res;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		string str;
		cin >> str;
		vector<int> chr(300, 0);
		for(int i = 0; i < str.length(); i++){
			chr[str[i]]++;
		}
		priority_queue<int> Q;
		for(int i = 0; i < 300 ; i++){
			if(chr[i])
				Q.push(chr[i]);
		}
		for(int i = 0; i < n; i++){
			int a = Q.top();
			Q.pop();
			a--;
			Q.push(a);
		}
		cout << solve(Q) << endl;
	}
	return 0;
}
