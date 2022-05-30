#include<bits/stdc++.h>

using namespace std;

void QHD(string s){
	int n = s.length();
	string s1 = s;
	for(int i = 0; i < n; i++){
		s1[i] = s[n - 1 - i];
	}
	int kq = 0;
	int F[101][101];
	for(int i = 0; i <= n; i++){
		F[0][i] = 0;
		F[i][0] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(s[i-1] == s1[j-1]){
				F[i][j] = F[i-1][j-1] + 1;
			}
			else 
				F[i][j] = max(F[i-1][j], F[i][j-1]);
			kq = max(kq, F[i][j]);
		}
		
	}
	cout << n - kq << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		QHD(s);
	}
	return 0;
}
