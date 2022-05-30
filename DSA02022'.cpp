#include<bits/stdc++.h>

using namespace std;

vector<string> str;

void Try(int i, string s){
	for(int j = 0; j <= 1;j++){
		if(j == 0) s.push_back('0');
		else s.push_back('2');
		if(i == 2){
			str.push_back(s);
		}
		else Try(i + 1, s);
		s.pop_back();
	}
}

int main() {
	vector<string> res;
	res.push_back("02/02/2");
	res.push_back("20/02/2");
	res.push_back("22/02/2");
	Try(0, "");
	for(auto it : res){
		for(auto i : str)
			cout << it << i << endl;
	}
	return 0;
}
