#include<bits/stdc++.h>

using namespace std;
vector<string> tr;
vector<int> res;
int n;
void input(){
	cin >> n;
	res.resize(n, 0);
	tr.resize(n);
	for(int i = 0; i < n; i++){
		cin >> tr[i];
		if(isdigit(tr[i][0])){
			istringstream ss(tr[i]);
			ss >> res[i];
		}
	}
}

int cal(int a, int b, string c){
	if(c == "+") return a + b;
	if(c == "-") return a-b;
	if(c == "*") return a*b;
	return a/b;
}

void solve(){
	for(int i = n/2 - 1; i >= 0; i--){
		res[i] = cal(res[2*i + 1], res[2*i + 2], tr[i]);
	}
	cout << res[0] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		input();
		solve();
	}
	return 0;
}
