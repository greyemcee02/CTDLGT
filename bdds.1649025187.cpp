#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		vector<pair<int, int>> vec(n);
		for(int i = 0; i < n; i++){
			cin >> vec[i].first >> vec[i].second;
		}
		if(n == 1) cout << 0 << endl;
		else if(n == 2){
			if(vec[0].first == vec[1].first)
				cout << 0 << endl;
			else
				cout << min(vec[0].second, vec[1].second) << endl;
		}
		else{
			int res = 0;
			int m = 1;
			while(m < vec.size() - 1){
				if(vec[m].fist == vec[m-1].first){
					if(vec[m].fist == vec[m+1].first){
						res += min(vec[m].second, vec[m-1].second + vec[m+1].second);
						vec[m].first = -1;
					}
					else{
						res += min(vec[m].second, vec[m-1].second);
					}
				}
				m++;
			}
			if(vec[n - 1].first == vec[n-2]vector.first)
				res += min(vec[n - 1].second, vec[n-2]vector.second);
				cout << res << endl;
		}
	}
	return 0;
}
