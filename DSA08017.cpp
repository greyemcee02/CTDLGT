#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		stack<string> stk;
		queue<string> Q;
		Q.push("6");
		Q.push("8");
		stk.push("6");
		stk.push("8");
		while(1){
			string s = Q.front();
			Q.pop();
			if(s.length() == n) break;
			else{
				Q.push(s+"6");
				Q.push(s + "8");
				stk.push(s +"6");
				stk.push(s +"8");
			}
		}
		while(!stk.empty()){
			cout << stk.top() << " ";
			stk.pop();
		}
		cout << endl;
	}
	
	return 0;
}
