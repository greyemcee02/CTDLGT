#include<bits/stdc++.h>

using namespace std;
int n;
vector<pair<char, char>> nums; 
void solve(int n, char dau, char tg, char dich){
	if(n == 1){
		nums.push_back({dau, dich});
		return;
	}
	solve(n-1, dau, dich, tg);
	solve(1, dau, tg, dich);
	solve(n-1, tg, dau, dich);	
}
int main() {
	cin >> n;
	solve(n, 'A', 'B', 'C');
	for(auto it : nums)
		cout << it.first << " -> " << it.second << endl;
	
	return 0;
}

