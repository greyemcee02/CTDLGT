#include<bits/stdc++.h>

using namespace std;
int n;
string str;

void Try(int i, string save, set<string> &res){
	for(int j = 1; j >= 0; j--){
		if(j == 1)
			save.push_back(str[i]);
		if(i == str.length() - 1) res.insert(save);
		else Try(i + 1, save, res);
		if(j == 1)
			save.pop_back();
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n ;
		cin >> str;
		set<string> res;
		Try(0, "", res);
		for(auto it : res){
			if(it != "")
			cout << it << " ";
		}	
		cout << endl;
	}
	return 0;
}



