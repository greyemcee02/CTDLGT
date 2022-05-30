#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<string> res;

void solve(string save) {
	int cnt = 0;
	for(int i = 0; i < save.size() - k + 1; i++){
		bool ok = true;
		for(int j = i; j < i + k; j++){
			if(save[j] == 'B') {
				ok = false;
				break;
			}
		}
		if(ok)
			cnt++;
	}
	if(cnt == 1) res.push_back(save);
}

void Try(int i, string save) {
	for(int j = 0; j <= 1; j++) {
		save.push_back(j + 'A');
		if(i == n - 1){
			solve(save);
		}
		else Try(i + 1, save);
		save.pop_back();
	}
}

int main() {
	cin >> n >> k;
	string save;
	Try(0, save);
	cout << res.size() << endl;
	for(auto it : res)
		cout << it << endl;
	return 0;
}
