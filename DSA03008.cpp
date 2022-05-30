#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
	return p1.second < p2.second;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		pair<int, int> CV[1000];
		for(int i = 0; i < n; i++){
			cin >> CV[i].first;
		}
		for(int i = 0; i < n; i++){
			cin >> CV[i].second;
		}
		int res = 1;
		sort(CV, CV + n, cmp);
		pair<int, int> p = CV[0];
		for(int i = 1; i < n; i++){
			if(CV[i].first >= p.second){
				res++;
				p = CV[i];
			}
		}
		cout << res << endl;
	}
	return 0;
}
