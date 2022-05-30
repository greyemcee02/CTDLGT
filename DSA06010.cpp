#include<bits/stdc++.h>

using namespace std;


int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, cnt = 0;
		string str;
		cin >> n;
		vector<int> check(10, 0);
		for(int i = 0; i < n; i++){
			cin >> str;
			if(cnt != 10){
				for(int j = 0; j < str.length(); j++){
					if(check[str[j] - '0'] == 0) cnt++;
						check[str[j] - '0'] = 1;
				}
			}
		}
		for(int i = 0; i <= 9; i++)
			if(check[i]) cout << i << " ";
		cout << endl;
	}	
	return 0;
}

