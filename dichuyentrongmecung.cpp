#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> F = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}}; 
vector<string> res;

char cv(int i){
	if(i == 0) return 'D';
	if(i == 1) return 'L';
	if(i == 2) return 'R';
	return 'U';
}

void Try(vector<vector<int>> grid, int h, int c, string s){
	if(grid[h][c] == 0) return;
	grid[h][c] = 0;
	for(int i = 0; i < F.size(); i++){
		if(h + F[i].first >= 0 && h + F[i].first <= n - 1 && c + F[i].second >= 0 && c + F[i].second <= n-1){
			if(grid[h + F[i].first][c + F[i].second] == 1){
				s.push_back(cv(i));
				if(h + F[i].first == n -1 && c + F[i].second == n-1){
					res.push_back(s);
				}
				else
				Try(grid, h + F[i].first,c + F[i].second, s );
				s.pop_back();
			}
		}
	}
	grid[h][c] = 1;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<vector<int>> grid(n, vector<int>(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> grid[i][j];
		}
		res.clear();
		Try(grid, 0, 0, "");
		if(res.size() == 0) cout << -1 << endl;
		else{
			cout << res.size() << " ";
			for(auto it : res)
				cout << it << " ";
			cout << endl;
		}
	}
	return 0;
}
