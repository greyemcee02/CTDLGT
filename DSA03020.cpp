#include<bits/stdc++.h>

using namespace std;

int solve(string &str){
	stack<int> stk;
	int res = 0;
	int open = 0, close = 0;
	for(auto it : str){
		if(it == '['){
			if(open < close){
				res+= close;
				close--;	
			}
			else{
				open++;
			}
		} 
		else{
			close++;
			if(close == open){
				close = 0;
				open = 0;
			}
		}
	}	
	return res;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		cout << solve(str) << endl;
	}
	return 0;
}
