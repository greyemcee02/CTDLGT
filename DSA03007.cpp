#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		long long res = 0;
		cin >> n;
		vector<long long> A(n), B(n);
		for(auto &it : A)
			cin >> it;
		for(auto &it : B)
			cin >> it;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end(), greater<int>());
		for(int i = 0; i < n; i++ )
			res += A[i]*B[i];
		cout << res << endl;
	}
	return 0;
}
