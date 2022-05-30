#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, k, res = 0;
	cin >> n >> k;
	map<int, int> mp;
	vector<int> Dodai(n);
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		Dodai[i] = str.length();
	}
	for(int i = 0; i < k; i++)
		mp[Dodai[i]]++;
	for(int i = 0; i < n; i++){
		if(k < n) mp[Dodai[k]]++;
		mp[Dodai[i]]--;
		k++;		
		res+=mp[Dodai[i]];
	}
	cout << res << endl;
	return 0;
}
