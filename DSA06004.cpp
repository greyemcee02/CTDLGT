#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> s1, vector<int> s2, int n, int m){
	vector<int> hop;
	vector<int> giao;
	vector<int> check(100001, 0);
	int p1 = 0, p2 = 0;
	while(p1 < n && p2 < m){
		if(s1[p1] == s2[p2]){
			if(check[s1[p1]] == 0){
				hop.push_back(s1[p1]);
				check[s1[p1]] = 1;
			}
			giao.push_back(s1[p1]);
			p1++;
			p2++;
		}
		else{
			if(s1[p1] < s2[p2]){
				if(check[s1[p1]] == 0){
					hop.push_back(s1[p1]);
					check[s1[p1]] = 1;	
				}
				p1++;
			}
			else{
				if(check[s2[p2]] == 0){
					hop.push_back(s2[p2]);
					check[s2[p2]] = 1;
				}
				p2++;
			}
		}
	}
	while(p1 < n){
		if(check[s1[p1]] == 0){
			hop.push_back(s1[p1]);
			check[s1[p1]] = 1;	
		}
		p1++;
	}
	while(p2 < m){
		if(check[s2[p2]] == 0){
			hop.push_back(s2[p2]);
			check[s2[p2]] = 1;
		}
		p2++;
	}
	for(auto it : hop)
		cout << it << " ";
	cout << endl;
	for(auto it : giao)	
		cout << it << " ";
	cout << endl;
}

int main(){
	int test;
	cin >> test;
	while(test--){
		int n, m;
		cin >> n >> m;
		vector<int> s1(n);
		vector<int> s2(m);
		for(int i = 0; i < n; i++)
			cin >> s1[i];
		for(int i = 0; i < m; i++)
			cin >> s2[i];
		solve(s1, s2, n, m);
	}
	return 0;
}
