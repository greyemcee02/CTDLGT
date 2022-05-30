#include<bits/stdc++.h>

using namespace std;
int R, C;
int A[501][501];
vector<pair<int, int>> xq = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
struct tree{
	int i, j;
	int day;
};

void input(){
	cin >> R >> C;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++)
			cin >> A[i][j];
	}
}

void solve(){
	int res = 0;
	int cnt = 0;
	queue<tree> Q;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(A[i][j] == 2){
				Q.push({i, j, 0});
			}
			else if(A[i][j] == 1) cnt++;
		}
	}
	while(!Q.empty()){
		tree tr = Q.front();
		Q.pop();
		for(auto it : xq){
			int h = tr.i + it.first;
			int c = tr.j + it.second;
			if( h >= 0 && h < R && c >= 0 && c < C){
				if(A[h][c] == 1){
					cnt--;
					Q.push({h, c, tr.day + 1});
					res = max(res, tr.day + 1);
					A[h][c] = 2;
				}
			}
		}
	}
	if(cnt == 0) cout << res << endl;
	else cout << -1 << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		input();	
		solve();
	}	
	return 0;
}
