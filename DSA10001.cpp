#include<bits/stdc++.h>

using namespace std;
struct ele{
	int x, y, dir, w; 
	//dir = 0 -> st
	// dir = 1 -> left
	// dir = 2 -> right
	// dir = 3 -> up
	// dir = 4 -> down
};

vector<pair<int, int>> nxt = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int n, m;
char A[501][501];
ele st, ed;
bool ok;

void input(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> A[i][j];
			if(A[i][j] == 'S') st = {i, j, 0, 0};
			if(A[i][j] == 'T') ed = {i, j, 0, 0};
		}
	}
	ok = false;
}

bool check(ele p1, int i){
	if(p1.x + nxt[i].first < 0 || p1.x + nxt[i].first >= n || p1.y + nxt[i].second < 0 || p1.y + nxt[i].second >= m ) return false;
	if(A[p1.x + nxt[i].first][p1.y + nxt[i].second] == '*') return false;
	if(p1.dir != 0 && i + 1 != p1.dir && p1.w == 2) return false;
	return true;
}

void BFS(ele st){
	queue<ele> Q;
	Q.push(st);
	A[st.x][st.y] = '*';
	while(!Q.empty()){
		ele curr = Q.front();
		Q.pop();
		for(int i = 0; i < nxt.size(); i++){
			if(check(curr, i)){
				int x = curr.x + nxt[i].first, y = curr.y + nxt[i].second;
				if(A[x][y] == 'T'){
					ok = true;
					return;
				}
				if(curr.dir == 0){
					Q.push({x, y, i + 1, 0});
				}
				else if(curr.dir == i + 1){
					Q.push({x, y, i + 1, curr.w});
				}
				else{
					Q.push({x, y, i + 1, curr.w + 1});
				}
				A[x][y] = '*';
			}
		}
	}
}

void solve(){
	BFS(st);
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;	
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
