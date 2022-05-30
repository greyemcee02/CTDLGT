#include<bits/stdc++.h>

using namespace std;

int solve(string str, int l, int r){
	while(l >=0 && r < str.length()){
		if(str[l] == str[r]){
			l--;
			r++;
		}
		else{
			l++;
			r--;
			break;
		}
	}
	if(l < 0 || r >= str.length()){
		l++;
		r--;
	}
	if(l <= r)
		return r-l + 1;
	else return 0;
}

void QHD(string str){
	int res = 1;
	for(int i = 0; i < str.length(); i++){
		res = max(res,solve(str, i, i));
		res = max(res,solve(str, i, i + 1));
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		QHD(str);
	}
	return 0;
}
