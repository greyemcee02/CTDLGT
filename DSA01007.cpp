#include<bits/stdc++.h>

using namespace std;

void Try(int i, string str, int n) {
	for(char j = 'A'; j <= 'B'; j++){
		str[i] = j;
		if(i == n - 1) cout << str << " ";
		else Try(i + 1, str, n);
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		string str(n, 'A');
		Try(0, str, n);
		cout << endl;
	}
	return 0;
}

