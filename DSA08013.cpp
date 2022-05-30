#include<bits/stdc++.h>

using namespace std;
int n;
char A[105][105];
pair<int, int> st, ed;
int res;
void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cin >> A[i][j];
	}
	cin >> st.first >> st.second;
	cin >> ed.first >> ed.second;
	res = 0;
}

void BFS(pair<int, int> u){
	queue<pair<pair<int, int>, int>> Q;
	Q.push({u, 0});
	A[u.first][u.second] ='X';
	while(!Q.empty()){
		pair<pair<int, int>, int> pr = Q.front();
		Q.pop();
		int x = pr.first.first, y = pr.first.second, w = pr.second;
		for(int i = x - 1; i >= 0; i--){
			if(A[i][y] == 'X') break;
			else{
				if(i == ed.first && y == ed.second){
					res = w+1;
					return;
				}	
				A[i][y] = 'X';
				Q.push({{i, y}, w+1});
			}	
		} 
		for(int i = x + 1; i < n; i++){
			if(A[i][y] == 'X') break;
			else{
				if(i == ed.first && y == ed.second){
					res = w+1;
					return;
				}	
				A[i][y] = 'X';
				Q.push({{i, y}, w+1});
			}	
		}
		for(int i = y-1; i >= 0; i--){
			if(A[x][i] == 'X') break;
			else{
				if(x == ed.first && i == ed.second){
					res = w+1;
					return;
				}	
				A[x][i] = 'X';
				Q.push({{x, i}, w+1});
			}	
		}
		for(int i = y + 1; i < n; i++){
			if(A[x][i] == 'X') break;
			else{
				if(x == ed.first && i == ed.second){
					res = w+1;
					return;
				}	
				A[x][i] = 'X';
				Q.push({{x, i}, w+1});
			}	
		}
	}
}

void solve(){
	if(st == ed) cout << 0 << endl;
	else{
		BFS(st);
		cout << res << endl;
	}
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
//1
//
//3
//
//.X.
//
//.X.
//
//...
//
//0 0 0 0

