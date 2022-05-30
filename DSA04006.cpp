#include<bits/stdc++.h>

using namespace std;
long long cntbit1, index, N;
long long l, r;
long long res;
long long cnt;
bool ok;
void countBit1(long long a){
	if(ok) return;
	if(a <= 1){
		cnt++;
		if(cnt <= r && cnt >= l) res+=a;
		else if(cnt > r) ok = true;
		return;
	}
	countBit1(a/2);
	countBit1(a%2);
	countBit1(a/2);
	
}

int main() {
	int test;
	cin >> test;
	while(test--){
		ok = false;
		cin >> N >> l >> r;
		res = 0;
		cnt = 0;
		countBit1(N);
		cout << res << endl;
	}
//	cout << 1125899906842621 - 100000 <<endl;
//	1125899906842623 1125899906742623 1125899906842623
	return 0;
}
