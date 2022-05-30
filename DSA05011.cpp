#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
int n, k;
long long res;
bool check(vector<int> num, int k){
	int s = 0;
	for(int i = n - 1; i >= 0; i--){
		s += num[i];
	}
//	for(int i = 0; i <= n - 1; i++)
//		cout << num[i];
//	cout << endl;
	if(s < k){
		return false;
	}
	if(s == k){
		res++;
		res = res%mod;
	} 
	return true;
}

void solve(){
	vector<int> num(n, 0);
	num[0] = 1;
	res = 0;
	int x = n - 1;
	while(1){
		if(check(num, k) || num[x] == 9){
			num[x] = 0;
			x--;
			while(x >= 0 && num[x] == 9){
				num[x] = 0;
				x--;
			}
			if(x == -1) break;
			num[x]++;
			x = n - 1;
		}	
		else num[x]++;
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;	
		solve();
	}
	return 0;
}
