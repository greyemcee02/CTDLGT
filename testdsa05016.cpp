#include<bits/stdc++.h>

using namespace std;
int n;
vector<long long> res;
void solve() {
	res.push_back(1);
	int p2 = 0, p3 = 0, p5 = 0;
	while(res.size() <= 10005){
		long long m2 = 2*res[p2];
		long long m3 = 3*res[p3];
		long long m5 = 5*res[p5];
		res.push_back(min(m2, min(m3, m5)));
		if(res[res.size() - 1] == m2) p2++;
		if(res[res.size() - 1] == m3) p3++;
		if(res[res.size() - 1] == m5) p5++;
	}
	
}

int main() {
	solve();
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		cout << res[n - 1] << endl;
	}
	return 0;
}
