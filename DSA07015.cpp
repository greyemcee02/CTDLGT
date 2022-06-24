#include<bits/stdc++.h>

using namespace std;
string str;

int gt(char a){
	if(a == '+' || a =='-') return 1;
	else if(a == '*' || a == '/') return 2;
	return 0;
}

long long check(long long k1, long long k2, string s){
	if(s == "+") return k1 + k2;
	if(s == "-") return k1-k2;
	if(s == "*") return k1*k2;
	return k1/k2; 
}

long long cal(string s){
	string s1;
	stack<long long> stk;
	stringstream ss(s);
	while(ss >> s1){
		if(isdigit(s1[0])){
			istringstream iss(s1);
			long long k;
			iss >> k;
			stk.push(k);
		}
		else{
			long long k1 = 0, k2 = 0;
			if(!stk.empty()){
				k2 = stk.top();
				stk.pop();
			}
			if(!stk.empty()){
				k1 = stk.top();
				stk.pop();
			}
			stk.push(check(k1, k2, s1));
		}
	}
	return stk.top();
}

string toSuf(){
	stack<char> stk;
	string s;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '(')
			stk.push(str[i]);
		else if(str[i] == ')'){
			while(!stk.empty() && stk.top()!='('){
				s.push_back(' ');
				s.push_back(stk.top());
				stk.pop();
			}
			if(!stk.empty() && stk.top() == '(') stk.pop();
		}
		else if(isdigit(str[i])){
			if(s.empty() || isdigit(s[s.length() - 1]))
				s.push_back(str[i]);
			else {
				s.push_back(' ');
				s.push_back(str[i]);
			}
		}
			
		else{
			s.push_back(' ');
			while(!stk.empty() && gt(str[i]) <= gt(stk.top())){
				s.push_back(' ');
				s.push_back(stk.top());
				stk.pop();
			}
			stk.push(str[i]);
		}
	}
	while(!stk.empty() && stk.top() != '('){
		s.push_back(' ');
		s.push_back(stk.top());
		stk.pop();
	}
	return s;
}

void solve(){
	cout << cal(toSuf()) << endl;
	//cout << toSuf() << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> str;		
		solve();
	}
	return 0;
}
