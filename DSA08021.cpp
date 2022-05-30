#include<bits/stdc++.h>

using namespace std;

struct C{
	int i;
	int j;
	int cnt;
};

vector<vector<int>> vs(1001, vector<int>(1001));
vector<vector<int>> A(1001, vector<int>(1001));
int n, m;

void BFS(int i, int j){
	queue<C> Q;
	Q.push({i, j, 0});
	vs[i][j] = 1;
	while(!Q.empty()){
		C u = Q.front();
		Q.pop();
		if(u.i == n-1 && u.j == m-1){
			cout << u.cnt << endl;
			return;
		}
		else{
			if(u.i+A[u.i][u.j]>=0 && u.i+A[u.i][u.j] < n && u.j >= 0 && u.j < m && !vs[u.i+A[u.i][u.j]][u.j]){
				Q.push({u.i+A[u.i][u.j],u.j, u.cnt+1});
				vs[u.i+A[u.i][u.j]][u.j] = 1;			
			}
			if(u.i >=0 && u.i < n && u.j+A[u.i][u.j] >=0 &&u.j+A[u.i][u.j] < m && !vs[u.i][u.j+A[u.i][u.j]] ){
				Q.push({u.i, u.j+A[u.i][u.j], u.cnt+1});
				vs[u.i][u.j+A[u.i][u.j]] = 1;
			}
		}
	}
	cout << -1 << endl;	
}

int main(){
	int test;
	cin >> test;
	while(test--){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> A[i][j];
				vs[i][j] = 0;
			}
		}
		BFS(0, 0);
		
	}
	return 0;
}
