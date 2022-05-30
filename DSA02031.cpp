#include<bits/stdc++.h>

using namespace std;
char c;
int n;

bool check(string str){

		for(int i = 1; i < str.length() - 1; i++){
			if(str[i] == 'A' && str[i+1] != 'E' && str[i-1] != 'E') return false;
			if(str[i] == 'E' && str[i+1] != 'A' && str[i-1] != 'A') return false;
		}
	return true;
}

int main(){
	cin >> c;
	n = c - 'A' + 1;
	string str;
	for(int i = 0; i < n; i++)
		str.push_back('A' + i);
	while(next_permutation(str.begin(), str.end())){
		if(check(str)) cout << str << endl;
	}
	return 0;
}
