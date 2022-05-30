#include<bits/stdc++.h>

using namespace std;
int a, mod = 1e9 + 7;
long long b;

long long pow(int a, long long b){
	if(b == 0) return 1;
	long long res = pow(a, b/2);
	if(b%2 == 0) return ((res%mod)*res)%mod;
	else return ((((res%mod)*res)%mod)*a)%mod;
}

int main() {
	while(1){
		cin >> a >> b;
		if(a == 0 && b == 0) break;
		cout << pow(a, b) << endl;
	}
	return 0;
}
