#include<iostream>
#include<queue>

using namespace std;

void solution(int mx, int n){
	if(n%2 == 0){
		if(mx <= n/2) cout << 1 << endl;
		else cout << -1 << endl;
	}
	else{
		if(mx <= n/2 + 1) cout << 1 << endl;
		else cout << -1 << endl;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		string str;
		cin >> str;
		int mx = 0, n = str.length();
		vector<int> count(300, 0);
		for(int i = 0; i < str.length(); i++){
			count[str[i]]++;
			mx = max(mx, count[str[i]]);
		}
		solution(mx, n);
	}
	return 0;
}
