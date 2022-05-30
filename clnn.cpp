#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n, k;
int res = INT_MAX;
vector<int> check(10, 0);
vector<string> F;
vector<int> vec;

void solve(){
	int mn = INT_MAX, mx = 0;
	for(int i = 0; i < n; i++){
		int s = 0;
		for(auto it : vec){
			s = s * 10 + (F[i][it-1] - '0');
		}
		mx = max(mx, s);
		mn = min(mn, s);
	}
	res = min(res, mx -mn);
}

void QL(int i){
	for(int j = 1; j <= k; j++){
		if(!check[j]){
			check[j] = 1;
			vec.push_back(j);
			if(i == k){
				solve();
			}
			else QL(i + 1);
			vec.pop_back();
			check[j] = 0;
		}
	}
}


int main() {
	cin >> n >> k;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		F.push_back(str);
	}
	QL(1);
	cout << res << endl;
	return 0;
}
