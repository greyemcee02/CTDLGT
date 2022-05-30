#include<iostream>

using namespace std;

int k;
string a, b;

void solve(){
	int nho = 0;
	string res = a;
	for(int i = a.length() - 1; i >= 0; i--){
		int s = a[i] - '0' + b[i] - '0' + nho;
		res[i] = (s % k) + '0';
		nho = s/k;
	}
	bool ok = false;
	for(auto it : res){
		if(it != '0') ok = true;
		if(ok) cout << it;
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> k >> a >> b;
		a = "0" + a;
		b = "0" + b;
		while(a.length() != b.length()){
			if(a.length() < b.length()) a = "0" + a;
			else if(a.length() > b.length()) b = "0" + b;
		}
		solve();
	}
	return 0;
}
