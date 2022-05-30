#include<bits/stdc++.h>

using namespace std;


int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		long long res = 0;
		long long sum = 0;
		for(int i = 0; i < str.length(); i++){
			sum = sum*10 + (str[i]-'0') *(i+1);
			res += sum;  
		}
		cout << res << endl;
	}
	return 0;
}

