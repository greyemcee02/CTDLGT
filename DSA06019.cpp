#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, tmp;
		cin >> n;
		map<int, int> m1;
		multimap<int, int> m2;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			m1[tmp]++;
		}		
		for(std :: map<int, int>:: iterator it = m1.end(); it != m1.begin(); it--){
			if(it == m1.end()) continue;
			pair<int, int> p ;
			p.first = it->second;
			p.second = it->first;
			m2.insert(p);
		}
		pair<int, int> p ;
		p.first = m1.begin()->second;
		p.second = m1.begin()->first;
		m2.insert(p);
		for(std :: multimap<int, int>:: iterator it = m2.end(); it != m2.begin(); it--){
			if(it == m2.end()) continue;
			int cnt = it->first;
			while(cnt--){
				cout << it->second << " ";
			}
		}
		int cnt = m2.begin()->first;
		while(cnt--){
			cout << m2.begin()->second << " ";
		}
		cout << endl;
	}
	return 0;
}
