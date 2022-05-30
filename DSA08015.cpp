#include<bits/stdc++.h>

using namespace std;
char A[31][31][31];
int x, y, z, res;
struct td{
	int x, y, z;
};
vector<td> ke = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
td st, ed;

void input(){
	cin >> x >> y >> z;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++)
			for(int k = 0; k < z; k++){
				cin >> A[i][j][k];
				if(A[i][j][k] == 'S'){
					st = {i, j, k};
					A[i][j][k] = '#';
				} 
				if(A[i][j][k] == 'E') ed = {i, j, k};
			}			
	}		
}

int check(td t1, td t2){
	if(t1.x + t2.x < 0 || t1.x + t2.x >= x) return 0;
	if(t1.y + t2.y < 0 || t1.y + t2.y >= y) return 0;
	if(t1.z + t2.z < 0 || t1.z + t2.z >= z) return 0;
	if(A[t1.x + t2.x][t1.y + t2.y][t1.z + t2.z] == '#') return 0;
	if(A[t1.x + t2.x][t1.y + t2.y][t1.z + t2.z] == 'E') return 2;
	return 1;
}

void BFS(){
	queue<pair<td, int>> Q;
	Q.push({st, 0});
	while(!Q.empty()){
		td u = Q.front().first; int b = Q.front().second; 
		Q.pop();
		for(auto v : ke){
			int k = check(u, v);
			if(k == 2){
				res = b + 1;
				return;
			}	
			else if(k == 1){
				Q.push({{u.x + v.x, u.y + v.y, u.z + v.z}, b + 1});
				A[u.x + v.x][u.y + v.y][u.z + v.z] = '#';
			}
		}
	}	
}

void solve(){
	res = -1;
	BFS();
	cout << res << endl;
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

//2
//3 4 5
//S....
//
//.###.
//
//.##..
//
//###.#
//
//#####
//
//#####
//
//##.##
//
//##...
// 
//#####
//
//#####
//
//#.###
//
//####E
// 
//1 3 3
//S##
//#E#
//###

