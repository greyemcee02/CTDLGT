#include<bits/stdc++.h>

using namespace std;


int main() {
	int n;
	cin >> n;
	string str;
	stack<int> stk;
	while(n--){
		cin >> str;
		if(str == "PUSH"){
			int a;
			cin >> a;
			stk.push(a);
		}
		else if(str == "PRINT"){
			if(stk.empty()) cout << "NONE" << endl;
			else{
				cout << stk.top() << endl;
			}
		}
		else {
			if(!stk.empty())
				stk.pop();
		}
	}
	return 0;
}
