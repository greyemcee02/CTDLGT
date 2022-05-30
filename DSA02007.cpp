#include<bits/stdc++.h>


using namespace std;



int main() {
	int test;
	cin >> test;
	while(test--) {
		string str;
		int k;
		cin >> k >> str;
		for(int i = 0; i < str.length() - 1; i++){
			string s = str;
			if(k == 0) break;
			char c = '0';
			for(int j = i + 1; j < str.length(); j++){
				c = max(c, str[j]);
			}
			if(c <= str[i]) continue;
			for(int j = i + 1; j < str.length(); j++){
				if(str[j] == c){
					string tmp = str;
					swap(tmp[i], tmp[j]);
					s = max(s, tmp);
				}
			}
			if(s > str){
				str = s;
				k--;
			}
		}
		cout << str << endl;
	}
	return 0;
}


