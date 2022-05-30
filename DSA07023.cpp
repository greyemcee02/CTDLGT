#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	cin.ignore();
	while(test--){
		string str;
		getline(cin, str);
		stack<string> stk;
		stringstream ss(str);
		string tmp;
		while(ss >> tmp){
			stk.push(tmp);
		}
		while(!stk.empty()){
			cout << stk.top() << " ";
			stk.pop();
		}
		cout << endl;
	}
	return 0;
}
