#include<bits/stdc++.h>

using namespace std;

int n;
vector<string> str;
vector<int> check;
vector<int> save;
int res = INT_MAX;

void solve(){
	int cnt = 0;
	for(int i = 0; i < n - 1; i++){
		int p1 = 0, p2 = 0;
		int tmp = 0;
		while(p1 < str[save[i]].length() && p2 < str[save[i+1]].length()){
			if(str[save[i]][p1] == str[save[i + 1]][p2]){
				tmp++;
				p1++;
				p2++;
			}
			else if(str[save[i]][p1] < str[save[i + 1]][p2]) p1++;
			else p2++;
		}
		cnt+=tmp;
	}
	res = min(res, cnt);
}

void Try(int i){
	for(int j = 0; j < n; j++){
		if(!check[j]){
			check[j] = 1;
			save[i] = j;
			if(i == n - 1){
				solve();
			}
			else Try(i + 1);
			check[j] = 0;
		}
	}
}

int main() {
	cin >> n;
	string tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		str.push_back(tmp);
		check.push_back(0);
		save.push_back(0);
	}
	Try(0);
	cout << res << endl;
	return 0;
}
