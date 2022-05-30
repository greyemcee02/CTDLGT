#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, mn = INT_MAX, mx = INT_MIN, tmp;
		cin >> n;
		set<int> st;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			st.insert(tmp);
			mn = min(mn, tmp);
			mx = max(mx, tmp);
		}
		cout << mx - mn + 1 - st.size() << endl;		
	}
	return 0;
}
