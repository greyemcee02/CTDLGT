#include<bits/stdc++.h>

using namespace std;

string str;

bool check(){
	stack<int> stk;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			stk.push(i);
		}
		else if(str[i] == ')'){
			if(!stk.empty()){
				int a = stk.top();
				stk.pop();
				if(a == i-2) return true;
				else{
					if(str[i+1] ==')'){
						if(!stk.empty() && stk.top() == a-1) return true;
					}
				}
			}
		}
	}
	return false;
}

int main(){
	int test;
	cin >> test;
	cin.ignore();
	while(test--){
		getline(cin, str);
		cout << (check()?"Yes":"No") << endl;
	}
	return 0;
}
