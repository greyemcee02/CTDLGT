#include<bits/stdc++.h>

using namespace std;

void solve(string str){
	if(str[0] != '0'){
		vector<int> DP(str.length() + 1, 0);
		DP[0] = 1;
		DP[1] = 1;
		for(int i = 1; i < str.length(); i++){
			if(str[i - 1]=='0'){
				if(str[i] == '0'){
					cout << 0 << endl;
					return;
				}
				else
					DP[i + 1] = DP[i];
			}
			else if(str[i-1] == '1'){
				if(str[i] == '0')
					DP[i + 1] = DP[i-1];
				else DP[i + 1] = DP[i-1] + DP[i];
			}
			else if(str[i-1] == '2'){
				if(str[i] > '0' && str[i] <= '6')
					DP[i + 1] = DP[i-1] + DP[i];
				else if(str[i] == '0')
					DP[i + 1] = DP[i-1];
				else DP[i + 1] = DP[i];
			}
			else{
				if(str[i] == '0'){
					cout << 0 << endl;
					return;
				}
				else
					DP[i + 1] = DP[i];
			}
		}
		cout << DP[str.length() ] << endl;
	}
	else cout << 0 << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		solve(str);
	}
	return 0;
}

