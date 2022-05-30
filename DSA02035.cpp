#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<string> num;
int res = INT_MAX;
vector<int> ngang;
vector<int> doc;
vector<int> checkn(10, 0);

void solve1(){
	int mn = INT_MAX, mx = INT_MIN;
	for(int i = 0; i < n; i++){
		int a = 0;
		for(int j = 0; j < k; j++){
			a = a*10 + (num[i][ngang[j]] - '0');
		}
		mn = min(mn, a);
		mx = max(mx, a);
	}
	res = min(mx - mn, res);
}


void Ngang(int i){
	for(int j = 0; j < k; j++){
		if(!checkn[j]){
			checkn[j] = 1;
			ngang.push_back(j);
			if(i == k - 1){
				solve1();
			}
			else Ngang(i+1);
			ngang.pop_back();
			checkn[j] = 0;
		}
	}
}

int main(){
	cin >> n >> k;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		num.push_back(str);
	}
	Ngang(0);
	cout << res << endl;
	return 0;
}



