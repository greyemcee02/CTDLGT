#include<bits/stdc++.h>

using namespace std;
string str1, str2;

string solve(string str){
	stack<int> stk;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			stk.push(i);
		}
		else if(str[i] == ')'){
			int k = stk.top();
			stk.pop();
			if(k > 0 && str[k-1] == '-'){
				for(int j = k + 1; j < i; j++)
					if(str[j] == '+' && str[j-1] != '(')
						str[j] = '-';
					else if(str[j] == '-' && str[j-1] != '(')
						str[j] = '+';
			}
		}
	}
	string s;
	for(auto it : str){
		if(it!= '(' && it != ')'){
			if(s.length() == 0){
				if(it =='+') continue;
				//s.push_back(it);
			}
			else{
				if(it == '+'){
					if(s[s.length() - 1] == '+' || s[s.length() - 1] == '-')
						continue;
				}
				else if(it == '-'){
					if(s[s.length() - 1] == '+' ){
						s[s.length() - 1] = '-';
						continue;
					}
					else if(s[s.length() - 1] == '-'){
						s[s.length() - 1] = '+';
						if(s.length() == 1) s.pop_back();
						continue;
					}				
				}
			}
			s.push_back(it);
		}
	}			
	return s;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> str1 >> str2;
		cout << ((solve(str1) == solve(str2))?"YES":"NO") << endl;
	}
	
	return 0;
}
