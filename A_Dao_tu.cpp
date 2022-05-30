#include<bits/stdc++.h>

using namespace std;
string str;

int main() {
	int test;
	cin >> test;
	cin.ignore();
	while(test--){
		getline(cin, str);
		stringstream ss(str);
		string res = "";
		string tmp;
		while(ss >> tmp){
			for(int i = 0; i < tmp.length()/2; i++){
				swap(tmp[i], tmp[tmp.length()-1-i]);
			}
			res += tmp + " ";
		}
		res.pop_back();
		cout << res << endl;
	}	
	return 0;
}
