#include<bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
long long solve(long long n, long long r){
	if(r == 0) return 1;
	long long res = solve(n, r/2);
	if(r%2==0) return ((res%mod)*res)%mod;
	else return ((((res%mod)*res)%mod)*n)%mod;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		string str;
		cin >> str;
		long long r = 0, n = 0;
		int i = 0;
		while(i < str.length()){
			n = n*10 + (str[i] - '0');
			r = r * 10 + (str[str.length()-1-i] - '0');
			i++;
		}
		cout << solve(n, r) << endl;
	}
	return 0;
}
